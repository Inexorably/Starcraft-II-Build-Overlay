#ifndef BUILDORDER_H
#define BUILDORDER_H

#include <vector>
#include <QString>

struct buildOrder{
    std::vector<int> supply;
    std::vector<QString> toBuild;
    int index;

    int currIndex();
    QString nextItem();
    QString prevItem();

    int totalItems();

    void initialize();
};

#endif // BUILDORDER_H
