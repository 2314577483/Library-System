//
// Created by add33 on 2/18/2022.
//

#ifndef FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_ITEM_H
#define FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_ITEM_H

#include "..\header\Shelf.h"


class Item :public LibraryItem{
private:
    std::string author;
    std::string year;
    std::string tag;
    std::string description;
    std::string content;
    std::string identifier;
    std::string availability;
    bool access;

    // getters and setters
public:
    const std::string& getYear() const;
    void setYear(std::string &year);

    const std::string &getTag() const;
    void setTag(std::string &tag);

    const std::string &getDescription() const;
    void setDescription(const std::string &description);

    const std::string &getContent() const;
    void setContent(const std::string &content);

    const std::string &getIdentifier() const;
    void setIdentifier(const std::string &identifier);

    const std::string &getAvailability() const;
    void setAvailability(const std::string availability);

    const std::string &getAuthor() const  { return author; }
    void setAuthor(const std::string Author) { author = Author; }

    bool isAccess() const;
    void setAccess(bool access);

public:
    Item();
    //explicit Item(std::string name);
    Item(std::string name, std::string year);
    Item(Item &item);
    ~Item();

    //void clearTag();
    //void addTag(std::string tag);

    std::vector<LibraryItem*> search(std::string arg, std::vector<LibraryItem*> list) override;
};



#endif //FINAL_PROJECT_ZLIU308_JLIN297_ZXIAO031_WFENG026_ITEM_H
