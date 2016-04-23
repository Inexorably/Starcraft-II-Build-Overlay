#include "buildorder.h"

int buildOrder::totalItems(){
    return (int)supply.size();
}

int buildOrder::currIndex(){
    return index;
}

QString buildOrder::nextItem(){
    if (toBuild.empty())
        return "No build selected";
    if (index >= toBuild.size() - 1)
        return currItem();
    index++;
    return toBuild[index];

}

QString buildOrder::prevItem(){
    if (toBuild.empty())
        return "No build selected";
    if (index <= 0)
        return currItem();
    index--;
    return toBuild[index];
}

void buildOrder::initialize(){
    index = 0;
}

QString buildOrder::currItem(){
    return toBuild[index];
}

void buildOrder::addItem(QString add){
    toBuild.push_back(add);
}
