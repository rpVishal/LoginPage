## Install Instructions:

__Step1:__ Open the link (github link) and go to ‘code’ option.

__Step2:__ Download zip folder. After downloading unzip the folder and copy it.

__Step3:__ Create one new folder(name of your choice) and then paste the unzip folder in that.

__Step4:__ Create two folder inside the new folder. Then rename the newly created folders with the name win32 and x64.

__Step5:__ Now open cmake application. If any other project is in use with cmake then go to file option in the above navbar and select delete cache.

__Step6:__ Now see below the option ‘where is the source code’ so in this locate the folder location of the folder we have pasted(unzip folder) and select that pasted unzip folder.

__Step7:__ After completing step6 now we have to select the folder for ‘where to build the binaries’. So, in this step we have to locate the folder for building the binaries now for this locate the folder win32 that we have created. Select win32 folder location.

__Step8:__ After selecting win32 folder now below we have a ‘configure’ button click on that. Pop menu will open in that ‘generator for the project will be selected automatically’.   Now for ‘optional platform for generator’ select win32 and after this click finish.

__Step9:__ After the configuration is done click on generate and after that click on open project.

__Step10:__ Project will get opened in Visual Studio. When the project gets opened we will see solution explorer in that we will have an ‘login’ project. Right click on ‘login’ and a menu will open in that there is a option ‘Set as Startup Project’ click on that.

__Step11:__ Click on the arrow which is on the left side of ‘login’ which have a dropdown menu and then after click for the dropdown menu for Source file. Then we will see main.cpp and usermanager.cpp.

__Step12:__ Now, Run Program by pressing ctrl+F5 or from the navigation menu.
