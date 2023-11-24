#ifndef EVENTDAO_H
#define EVENTDAO_H

#include <QObject>
#include <QDateTime>

class EventDAO
{
public:
    EventDAO();
    EventDAO(QString title);

    qint32 id() const;
    QString title() const;
    QString description() const;
    QDateTime begin_date() const;
    QDateTime end_date() const;
    QString event_type() const;

private:
    qint64 m_id;
    QString m_title;
    QString m_description;
    QDateTime m_begin_date;
    QDateTime m_end_date;
    QString m_event_type;
};

#endif // EVENTDAO_H
