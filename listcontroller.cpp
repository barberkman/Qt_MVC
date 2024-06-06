#include <vector>

#include <QString>

#include "listcontroller.h"

namespace detail {

class ListModel : public QAbstractListModel
{
public:
    ListModel(QObject* parent = nullptr)
        : QAbstractListModel{ parent }
    {}

    void addData(const QString& data)
    {
        beginInsertRows(QModelIndex{}, rowCount(), rowCount());
        m_data.push_back(data);
        endInsertRows();
    }

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override
    {
        Q_UNUSED(parent)
        return static_cast<int>(m_data.size());
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        try {
            const QString& data = m_data.at(index.row());

            switch (role) {
            case Qt::DisplayRole:
                return QVariant::fromValue(data);
                break;
            default:
                break;
            }
        } catch (...) {}

        return QVariant{};
    }

private:
    std::vector<QString> m_data;
};

} // namespace detail

ListController::ListController(QObject *parent)
    : QObject{ parent },
    m_model{ new detail::ListModel }
{

}

QAbstractListModel *ListController::model() const
{
    return m_model.get();
}

void ListController::addData(const QString &data)
{
    m_model->addData(data);
}
