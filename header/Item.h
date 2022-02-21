//
// Created by add33 on 2/18/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_ITEM_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_ITEM_H

#include "Shelf.h"
#include "BookFormat.h"
#include "BookStatus.h"

namespace lb {
    class Item :public LibraryItem{
    private:
        Shelf* location;
        int year;
        std::vector<std::string> tag;
        std::string description;
        std::string content;
        std::string identifier;
        BookStatus availability;
        bool access;

        // getters and setters
    public:
        Shelf* getLocation() const;
        void setLocation(Shelf *location);
        int getYear() const;
        void setYear(int year);
        const std::vector<std::string> &getTag() const;
        void setTag(const std::vector<std::string> &tag);
        const std::string &getDescription() const;
        void setDescription(const std::string &description);
        const std::string &getContent() const;
        void setContent(const std::string &content);
        const std::string &getIdentifier() const;
        void setIdentifier(const std::string &identifier);
        BookStatus getAvailability() const;
        void setAvailability(BookStatus availability);
        bool isAccess() const;
        void setAccess(bool access);

    public:
        Item();
        explicit Item(std::string name);
        Item(std::string name, int year);
        ~Item() override;
        void clearTag();
        void addTag(std::string tag);
        std::vector<LibraryItem *> search() override;
    };
}


#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_ITEM_H
