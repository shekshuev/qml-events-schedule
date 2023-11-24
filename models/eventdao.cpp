#include "eventdao.h"

EventDAO::EventDAO()
{

}

EventDAO::EventDAO(QString title) {
    this->m_title = title;
}

qint32 EventDAO::id() const
{
    return this->m_id;
}

QString EventDAO::title() const
{
    return this->m_title;
}

QString EventDAO::description() const
{
    return this->m_description;
}

QDateTime EventDAO::begin_date() const
{
    return this->m_begin_date;
}

QDateTime EventDAO::end_date() const
{
    return this->m_end_date;
}

QString EventDAO::event_type() const
{
    return this->m_event_type;
}
