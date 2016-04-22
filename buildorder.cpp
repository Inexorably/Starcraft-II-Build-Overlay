#include "buildorder.h"

int buildOrder::totalItems(){
    return supply.size();
}

int buildOrder::currIndex(){
    return index;
}

QString buildOrder::nextItem(){
    if (index >= supply.size())
        return "UPPER_LIMIT";
    index++;
    return toBuild[index];

}

QString buildOrder::prevItem(){
    if (index <= 0)
        return "LOWER_LIMIT";
    index--;
    return toBuild[index];
}

void buildOrder::initialize(){
    index = 0;
}
