//
// Created by 肖子超 on 2022/2/19.
//

#ifndef INC_100_PROJECT_VIDEO_H
#define INC_100_PROJECT_VIDEO_H

#include "Item.h"
namespace lb {
    class Video: public Item{
    private:
        std::string creator;
        int duration;
    public:
        std::string getCreator() {return creator;}
        int getDuration() {return duration;}
        void setCreator(std:: string Creator) {creator = Creator;}
        void setDuration(int Duration) {duration = Duration;}
    };
}
#endif //INC_100_PROJECT_VIDEO_H
