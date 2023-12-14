# BD Meteorological System

You will extend the home assignment one. Read all the instructions of assignment one. Here are the additional instructions.

(a)(i) Create a City structure that will have the following members: name (string type), population (int type), and averageTemperature (float type).

(ii) In the main function, create an array of size N of City structure type. This array will be used by all the functions. You will have a lower case n to keep track of the number of values in the array. You will pass this array and # of employees (n) as arguments to the functions.

(b) Create a function “takeCitiesInfoFromKeyboard” that takes a City structure array and n as parameters. It takes information of one City from keyboard and stores in the City structure array. Do you know that arrays are passed by reference?

(c) Create a function “findCityWithHighestTemperature” that takes a City structure array and n as parameters. It finds and displays the city’s information that has the highest temperature.

(d) Create a function “displayAllCitiesInfo” that takes a City structure array and n as parameters. It displays those Cities’ information whose temperatures are less than half of the highest Temperature in a tabular format with following values (including the given column heading):

City Name – City Population – City Temperature

         ?                          ?                              ?     

g) Write other necessary code to create the following menu system similar to assignment one. The following menu will always be displayed except if exited by pressing ‘q’.

 

======= BD Meteorological System =========


• Enter ‘x’, to take information of one city into the City structure array of size N.

• Enter ‘y’, to find and display the info of City with the highest temperature.

• Enter ‘z’, to display the information of Cities with less than half of the highest temperature in tabular format.

• Enter ‘q’, quit/exit the menu system.

• For any other input, display “Invalid Input”

After the menu is displayed, the program will prompt the user “Enter your choice: “ to enter a choice from the menu. After user enters his choice, using switch case the program will call appropriate functions to do the task.
