#include "AGEpollEventLoop.h"

AGEpollEventLoop::AGEpollEventLoop()
{
    connection_cout_ = 0;
    epoll_fd_ = -1;
}

AGEpollEventLoop::~AGEpollEventLoop()
{
    if(events_)
        delete [] events_;
}

bool AGEpollEventLoop::init()
{
    epoll_fd_ = epoll_create1 (0);
    if (epoll_fd_ == -1)
    {
        throw std::exception();
    }

    return true;
}

void AGEpollEventLoop::setConnectionCount(uint32_t numConnections)
{
    events_ = new epoll_event[numConnections];
    max_connection_cout_ = numConnections;
}

void AGEpollEventLoop::start()
{
    auto thread_func = std::bind(&AGEpollEventLoop::epollThreadFunc, this);
    epoll_thread_ = std::thread(thread_func);
}

bool AGEpollEventLoop::epollThreadFunc()
{
    //std::unique_lock<std::mutex> lock_(mutex_);
    //star_wait_.wait(lock_);
    std::cout << "starting Epoll Thread" << std::endl;

    int numFdsResdy = 0;
    while(1)
    {
        numFdsResdy = epoll_wait (epoll_fd_, events_, max_connection_cout_, -1);

        for(uint32_t idx = 0; idx < numFdsResdy; ++idx)
        {
            if((events_[idx].events & EPOLLIN))
            {
                AGExchangeSession *session = (AGExchangeSession *) events_[idx].data.ptr;
                if (!session->onReadReady()) {
                    removeSession(session);
                }
            }
            else //if((events_[idx].events & EPOLLHUP))
            {
                AGExchangeSession *session = (AGExchangeSession *) events_[idx].data.ptr;
                removeSession(session);
            }
        }

        if(0 == connection_cout_)
        {
            std::cout << "All session are done !" << std::endl;
            return true;
        }
    }
    return true;
}

void AGEpollEventLoop::join()
{
    epoll_thread_.join();
}

bool AGEpollEventLoop::addSession(AGExchangeSession* session)
{
    if(-1 == epoll_fd_)
    {
        return false;
    }
    epoll_event event;
    event.data.ptr = (void*)session;
    event.events = EPOLLIN | EPOLLRDHUP | EPOLLERR;//EPOLLIN | EPOLLHUP | EPOLLRDHUP;
    int ret = epoll_ctl (epoll_fd_, EPOLL_CTL_ADD, session->getSocketFd(), &event);
    if(-1 == ret)
    {
        return false;
    }
    ++connection_cout_;

    return true;
}

void AGEpollEventLoop::removeSession(AGExchangeSession* session)
{
    epoll_event event;
    event.data.fd = session->getSocketFd();
    event.events = EPOLLIN;
    int ret = epoll_ctl (epoll_fd_, EPOLL_CTL_DEL, session->getSocketFd(), &event);
    if(-1 == ret)
    {
        std::cout << "Error in epoll_ctl" << std::endl;
        return;
    }
    --connection_cout_;
}
