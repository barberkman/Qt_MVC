#ifndef LISTCONTROLLER_H
#define LISTCONTROLLER_H

#include <QObject>
#include <QSharedPointer>
#include <QAbstractListModel>

namespace detail {
class ListModel;
}

class ListController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* model READ model CONSTANT FINAL)
public:
    explicit ListController(QObject *parent = nullptr);

    QAbstractListModel* model() const;

    void addData(const QString& data);

private:
    QSharedPointer<detail::ListModel> m_model;
};

#endif // LISTCONTROLLER_H
