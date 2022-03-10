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
  
# Phase III
![image](https://user-images.githubusercontent.com/49822431/157553687-a2c8666d-6b6b-4ad9-9b5c-eed5071a2fd2.png)

  In our project, we will use Composite Pattern as the main pattern. Maybe we will add some Strategy Pattern features in the future. The Composite Pattern can easily build up the structure of our classes, it can let us know what kind of class we need for our project. In the new UML diagram we have LibraryItem and LibraryUser as Component, User and Item as Composite, the other derived class are leaves. The Composite Pattern can help us on setting up the default behavior. It will be really easy for us to build the project at the beginning.

  The reason we use Composite Pattern is that "book", "article" and "video" are primitives, and we can add the "category (shelf)"as the composite, so that we can store the "book"," article " and "video" in the "category (shelf)". Meanwhile, we also save "book", "article", "video" and "category (shelf)" into the "libraryItem". Thus "libraryItem" is used as a component, which will constitute our Composite Pattern. We are using this design pattern to improve efficiency and help us write code better and clearer.


 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 Welcome Mneu
 
 ![image](https://user-images.githubusercontent.com/49822431/157552734-020af8c2-9b20-4c29-b2f7-22fcb574bb4f.png)

 Register Menu
 
 ![image](https://user-images.githubusercontent.com/49822431/157552943-2ff3866b-fcb3-437a-a070-bd5d2ce41efc.png)

 Libraian Function Menu
 
 ![image](https://user-images.githubusercontent.com/49822431/157553010-ed08df8f-f459-45ec-ad95-c5c43fb7b338.png)
 
 Libraian Add Function Menu
 
 ![image](https://user-images.githubusercontent.com/49822431/157553484-f794bd69-0ace-40af-aba8-fdced4ffed44.png)
 
 Libraian Add Book Process
 
 ![image](https://user-images.githubusercontent.com/49822431/157553060-2e38286b-f97e-43be-9930-d8cab24bf650.png)

 Libraian Add Article Process
 
 ![image](https://user-images.githubusercontent.com/49822431/157553437-4724531c-ef64-44e3-a46d-f4ea208a4c07.png)
 
 Libraian Add Video Process
 
 ![image](https://user-images.githubusercontent.com/49822431/157553531-380b299a-9061-4a89-9b9b-cbb14486c135.png)

 Student Function Menu
 
 ![image](https://user-images.githubusercontent.com/49822431/157552784-b6bdda68-6481-4992-b88a-89614663710a.png)
 
 Student Search Menu
 
 ![image](https://user-images.githubusercontent.com/49822431/157552879-e63fa09c-d78d-47f9-989a-0888c548165b.png)
 
 Valgrind
 
 ![image](https://github.com/cs100/final-project-zliu308-jlin297-zxiao031-wfeng026/blob/b8ea61a0c87b0fb8fb7354a3fc9c5192aaac0ef8/Screenshots/Valgrind.png)

 
 ## Installation/Usage
 ![Final Project UML](https://user-images.githubusercontent.com/97133827/157556499-0d831a8c-ca3d-43ba-88b4-6b2393fc0107.png)
 
 You can either use Linux or Windows system to compiler our program.
 
 Windows: Put all files into a project after downloading them, then run the solution file.
 
 Linux: Use CMake to compiler the program after downloading them. Remember to use "git clone --recursive <github-repo-url>" command to fully clone the google test into the local repository if you decide to use the command line to execute the program.
 
 Use recursive clone command to download all fils including gtest:
 > $ git clone --recursive <github-repo-url>
 
 Use CMake to compiler the program:
 > $ CMake3 .
 
 > $ make
 
 > $ ./main
 
 Run the google tests:
 > $ ./test
 
 Run the valgrind by following commands:
 > $ g++ -g -O0 -o main main.cpp
 > $ ./main
 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
