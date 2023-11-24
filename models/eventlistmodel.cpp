#include "eventlistmodel.h"

EventListModel::EventListModel(QObject * parent): QAbstractListModel(parent)
{
    m_roleNames[NameRole] = "name";
    m_roleNames[HueRole] = "hue";
    m_roleNames[SaturationRole] = "saturation";
    m_roleNames[BrightnessRole] = "brightness";
    for(const QString& name : QColor::colorNames()) {
        m_data.append(QColor(name));
    }
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
    const QColor& color = m_data.at(row);
    qDebug() << row << role << color;
    switch(role) {
        case NameRole:
            return color.name();
        case HueRole:
            return color.hueF();
        case SaturationRole:
            return color.saturationF();
        case BrightnessRole:
            return color.lightnessF();
    }

    return QVariant();
}

QHash<int, QByteArray> EventListModel::roleNames() const
{
    return m_roleNames;
}

void EventListModel::insert(int index, const QString &colorValue)
{
    if (index < 0 || index > m_data.count()) {
        return;
    }
    QColor color(colorValue);
    if (!color.isValid()) {
        return;
    }
    emit beginInsertRows(QModelIndex(), index, index);
    m_data.insert(index, color);
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

QColor EventListModel::get(int index)
{
    if(index < 0 || index >= m_data.count()) {
        return QColor();
    }
    return m_data.at(index);
}

int EventListModel::count() {
    return m_data.count();
}

