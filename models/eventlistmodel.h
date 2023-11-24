#ifndef EVENTLISTMODEL_H
#define EVENTLISTMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "eventdao.h"

class EventListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum RoleNames {
        IdRole = Qt::UserRole,
        TitleRole,
        DescriptionRole,
        BeginDateRole,
        EndDateRole,
        EventTypeRole
    };

    EventListModel(QObject * parent = 0);
    ~EventListModel();

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    int count();

    Q_INVOKABLE void insert(int index, const QString& colorValue);
    Q_INVOKABLE void append(const QString& colorValue);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void clear();

    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_INVOKABLE EventDAO get(int index);

signals:
    void countChanged(int);

protected:
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QList<EventDAO> m_data;
    QHash<int, QByteArray> m_roleNames;
};

#endif // EVENTLISTMODEL_H
