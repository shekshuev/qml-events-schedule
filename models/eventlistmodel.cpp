#include "eventlistmodel.h"

EventListModel::EventListModel(QObject * parent): QAbstractListModel(parent)
{ 
    m_roleNames[IdRole] = "id";
    m_roleNames[TitleRole] = "title";
    m_roleNames[DescriptionRole] = "description";
    m_roleNames[BeginDateRole] = "begin_date";
    m_roleNames[EndDateRole] = "end_date";
    m_roleNames[EventTypeRole] = "event_type";
}


EventListModel::~EventListModel() {}

int EventListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

QVariant EventListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }
    const EventDAO& dao = m_data.at(row);
    switch(role) {
        case IdRole:
            return dao.id();
        case TitleRole:
            return dao.title();
        case DescriptionRole:
            return dao.description();
        case BeginDateRole:
            return dao.begin_date();
        case EndDateRole:
            return dao.end_date();
        case EventTypeRole:
            return dao.event_type();
    }
    return QVariant();
}

QHash<int, QByteArray> EventListModel::roleNames() const
{
    return m_roleNames;
}

void EventListModel::insert(int index, const QString &title)
{
    if (index < 0 || index > m_data.count()) {
        return;
    }
    EventDAO dao(title);
    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, dao);
    emit endInsertRows();
    emit countChanged(m_data.count());
}

void EventListModel::append(const QString &colorValue)
{
    insert(count(), colorValue);
}

void EventListModel::remove(int index)
{
    if(index < 0 || index >= m_data.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

void EventListModel::clear()
{
    emit beginRemoveRows(QModelIndex(), 0, count());
    m_data.clear();
    emit endRemoveRows();
    emit countChanged(m_data.count());
}

EventDAO EventListModel::get(int index)
{
    if(index < 0 || index >= m_data.count()) {
        return EventDAO();
    }
    return m_data.at(index);
}

int EventListModel::count() {
    return m_data.count();
}

