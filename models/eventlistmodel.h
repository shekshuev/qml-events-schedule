#ifndef EVENTLISTMODEL_H
#define EVENTLISTMODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QDebug>

class EventListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum RoleNames {
        NameRole = Qt::UserRole,
        HueRole = Qt::UserRole+2,
        SaturationRole = Qt::UserRole+3,
        BrightnessRole = Qt::UserRole+4
    };

    explicit EventListModel(QObject * parent = 0);
    ~EventListModel();

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    int count();

    Q_INVOKABLE void insert(int index, const QString& colorValue);
    Q_INVOKABLE void append(const QString& colorValue);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void clear();

    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_INVOKABLE QColor get(int index);

signals:
    void countChanged(int);

protected:
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QList<QColor> m_data;
    QHash<int, QByteArray> m_roleNames;
};

#endif // EVENTLISTMODEL_H
