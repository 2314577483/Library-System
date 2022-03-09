//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_VIDEO_H
#define INC_100_PROJECT_VIDEO_H

#include "../header/Item.h"

class Video: public Item{
private:
    std::string duration;
public:
    std::string getDuration() {return duration;}
    void setDuration(int Duration) {duration = Duration;}
    //virtual std::vector<LibraryItem*> search();
};

#endif //INC_100_PROJECT_VIDEO_H
