# Library System

Authors: [Zhenjie Liu](https://github.com/2314577483), [Zichao Xiao](https://github.com/Zichao031), [William Feng](https://github.com/WwwwwFeng), [Jiale Lin](https://github.com/jlin297)

## Project Description
### Why Is It Interesting To Us
A library system is boring to be honest, but the sub-systems like data-storage system and data-search engine excited us. In today's era of big data, more or less everyone's information is collected, and the use of this information can give enterprises an advantage in expanding their influence. So the way to store and use big data is a hot trend nowadays. Before the use of big data is the storage and use of data, so mastering various methods of data processing is the cornerstone for us to stand on the top of the trend, and this is the reason why the topic intersting to us. By designing a library system, we can start to be exposed to the way of data processing. Searching, adding, and recommending books will allow us to become more and more familiar with how to handle data. This will make it easier for us to get started when we enter the company in the future.

We want to design a library system that allows users to register for accounts.
Once logged in, the user can borrow books, show the date books needs to return, or show available books. Books are organized by different genres/sub-genres. 
The system allows to display all books or books under a selected genre or use combined criteria (for example, books by a particular author under a particular genre).
Allows staff accounts to add/edit/delete books.
Libraries can also provide users with book recommendations based on their previous reading history. 
This is a complete library software management system. 
We can improve productivity and efficiency by designing and implementing a software that not only facilitates students to borrow books, but also facilitates staff to manage books.
### Languages/Tools/Technologies 
 
   [C++](https://www.cplusplus.com/) - C++ 11 is the primary programming language for this project.

   [Clion](https://www.jetbrains.com/clion/) - A high level C and C++ text editor.
   
   [CMake](https://cmake.org/) - An open-source, cross-platform family of tools designed to build, test and package software. 

   [Git](https://git-scm.com/) - A distributed version control system that allow us to complete different commands.

   [Git Hub](https://github.com) - A version control system that different partners can work the same project together online. It's the main version control system that we will use through the whole project.
  
   [Google Test Framework](https://github.com/google/googletest) - A tool where we can create our own test files and test if the code of this project works correctly.

   [Vim](https://www.vim.org/) - A text editor on Linux.
   
   [Valgrind](https://valgrind.org/) - An instrumentation framework for building dynamic analysis tools. We will use it to check if there are any memeroy leak problems on our project.

   [Visual Studio](https://visualstudio.microsoft.com/vs/features/cplusplus/) - A high level C and C++ text editor. This is the main text editor we will use for this project.

### Input/Output Of Project
   Input - We will require users to create their own library accounts when they first use the library system. After that, the information of acounts will be automatically saved on the server. When they next log in the system, we will compare the information entered to the database to match whether the account information was entered correctly. Other inputs will include the inforamtion of books like book name, authors name, ISBN number, cover, genre, availability, price, location. 
   
   Output - The system will automatically matched the information from the users input. If the book is available, the system will output the name, author name, ISBN number, cover, genre, price and location of the book to help users find it.

# Phase II
## Class Diagram
![Diagram](https://user-images.githubusercontent.com/97133827/153089385-0720754e-fd14-4b2d-8c54-c30c64a11230.png)

  In our project, we first have one or more Shelves to build up the library. Each Shelf is made up of zero or more Items. The Item class will have three child classes: Article, Book, and Video. The Article, in other words, peer review, is a summary of the book. It can introduce the book to the user. The Book class contains all necessary parts of the book, like author, publisher, format, ISBN, etc. As a system, we must have a User class to determine what role the user is. The User class is inherited by three classes: Newuser, Librarian, and Student. Each associated class will contain the account and password of the user, and it will determine the user type in order to give different users different authority. Besides the Student class, we create a child class called accountDebt to check if the student has enough money to borrow books.
  
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with a reader (using Calendly). Your entire team must be present. This meeting will occur on week 8 but NOT during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
