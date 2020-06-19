AVC-Project
Team 9: Repository for ENGR101 Project 3

Project 3 Plan 

Members:-
  Natnael Gebremichael
  Corban Van Manen
  Ruben Nithyaganesh
  Alex Smith

Communication tool:-
  Facebook messenger, Discord

Roles:-
- Ruben Nithyaganesh:   Project Manager
- Corban Van Manen:     Software Architect
- Natnael Gebremichael: Testing and documentation
- Alex Smith:           Testing and documentation

Objectives:- 

4th June - Start Project
- Complete group plan
- get SFML installed on all team computers
- Ensure all members are included in communication channels.

6th June - Get Robot code compiling and working correctly
- By this date all members should be able to compile and run code for robot, and be able to 
edit code/output of program
- Ensure all the right versions of MinGW, SFML, correct makefiles etc. necessary in order to complete this

9th June - Core
- Have code for core finished and tested

12th June - Completion
- Have code for completion finished and tested

18th June - Challenge
- Have code for challenge finished and tested


Setup Instructions:

1. Go to https://bit.ly/3djPNbz 
2. Right click on the folder named “All Downloads Needed” and click download, it will say “zipping” for a while, have patience    and wait (Note: If your browser prompts asking if you want to leave this site, click leave)

3. If using google chrome, wait for the download in the bottom left of chrome to finish downloading. If using edge, click “save”  when prompted

4. If using google chrome, click on the download when it is finished in the bottom left of chrome. If using edge, click open when the download finishes. This should open the zip file in file explorer

5. Drag and drop the folder that pops up onto your desktop, wait for it to extract and copy

6. Once finished extracting, double click to open the folder

7. Double click on “winrar-x64-590.exe”

8. If a popup appears, click yes

9. In the window that appears, click install

10. In the new windows that appears, click okay

11. Close the new file explorer window that pops up containing winrar content

12. Go back into the “All Downloads Needed folder”

13. Double click on “geany-1.36_setup.exe”

14. If a popup appears, click yes

15. In the windows that appears, click next

16. Click I Agree

17. Click next

18. Click next

19. Click install

20. Once finished installing click finish, and restart your computer. After restarting and logging back in, open the "All Downloads Needed folder" again

21. Go back into the “All Downloads Needed folder”

22. Double click “tdm-gcc-5.1.0-3.exe”

23. In the windows that appears, uncheck “Check for updated files on the TDM-GCC server”

24. Click create

25. Click next

26. Click next

27. Click install

28. Once finished installing, click next

29. Uncheck “Read the TDM-GCC README file (recommended)”

30. Click finish, and restart your computer. After logging back in, open the "All Download Needed folder"

31. Go back into the “All Downloads Needed folder”

32. Double click, “i686-7.3.0-release-posix-dwarf-rt_v5-rev0 (1).7z”

33. This should open a new winrar window, if an extra pop up window shows telling you to buy winrar, close it, winrar is a free program

34. Once closed, the actual winrar window will be very small, click hold and drag the bottom right hand corner of the window to expand the window

35. Open file explorer from your taskbar

36. On the left hand side, scroll down until you see a drive with name with drive letter (C:), e.g. “Local Disk (C:)”, “My Disk (C:), and click on it

37. Go back to the winrar window, click and hold on the mingw32 folder, and drag it onto some whitespace on the (C:) file explorer window to extract and copy it to the root of the C drive

38. On the right hand side of windows explorer, find “This PC” and right click on it

39. In the drop down menu that appears, click “Properties”

40. In the window that appears, look to the left hand side and click “Advanced system settings”

41. If a pop up appears click yes

42. In the new window that appears, towards the bottom click “Environment Variables”

43.In the new window, under the system variables box, and under the variable column, find “Path” and click on it

44. Click “edit”

45. In the top left of the window, click new and in the text box it jumps you to, type “C:\mingw32\bin” (Do not type the quotation marks)

46. Click ok

47. In the previous window, click ok

48. In the previous window, click ok

49. In the previous window, click ‘X’ to close out of the system window

50. Go back into the “All Downloads Needed folder”

51. Double click “AVC_Win10.zip”

52. A winrar window will pop up

53. Open file explorer in the task bar again

54. Open your (C:) drive on the left again

55. Back in the winrar window, drag and drop the “AVC_Win10” folder into white space on the (C:) drive, to extract and copy it to the root of the (C:) drive

56.Right click on the newly copied “AVC_Win10” folder

57. In the drop down menu, click rename, and type “Project” (Do not include quotations) and hit enter (make sure to include the capital letter P)

58. Double click on the newly copied “Project” folder

59. You should see “AVC_robot” and “AVC_server”

60. Go back into the “All Downloads Needed” folder

61. Double click the “Files” folder

62. Click and hold on SFML, and drag and drop it into the “Project” folder

63. In the “Project” folder, double click on “AVC_robot”

64. Go back into the “Files” window, an press the keys “Control” and “A” at the same time to select all the files

65. Click and hold, and drag and drop the files inside the “AVC_robot” folder currently open in the separate window (make sure you drop the files into white space), this will move all the files to the “AVC_robot” folder. When a window pops up asking if you want to replace files, click on “Replace the files in the destination”

66. In the “AVC_robot” folder, right click on the “robot” application

67. In the drop down menu, click delete

68. Do the exact same as you did for the “robot” application, with the “robot.o” file

69. Go back into the "Project" folder

70. Double click on the "AVC_server" folder

71. scroll down until you find the "server3" application, and the "server3.o" file

72. Right click on each of them, and in the drop down menu select delete

73. Go back to the "All Downloads Needed folder" and double click on files

74. double click on "Server makefile"

75. Click and hold on "makefile" and drag and drop it into the "AVC_sever" folder you should currently be in. When prompted by a pop up window if you want to replace the file, click "yes"

76. Go to your desktop, and double click “Geany” to start geany

77. Towards the top left, there should be a “Open” button with a picture of a folder, click on it

78. In the window that appears, on the left hand side, yet again find your (C:) drive and click on it

79. Find the “Project” folder and double click on it

80. Find the "AVC_server" folder and double click on it

81. Find the "server3.cpp" file and click on it once

82. In the bottom right hand corner of the window click open

83. In the same top bar that the "Open" button was located, find the "Build" button with a picture of a brick

84. Click on the arrow next to it

85. In the drop down menu, click on “Set Build Commands”, this should open a new window

86. There will be a number of boxes, under the “Independent commands” subtitle, find the first box named “Make”

87. To the right of that box, there should be a textbox that says “make”

88. Delete the contents of this text box, and instead type “mingw32-make” (Do not include the quotation marks)

89. In the bottom right hand corner of the window, click ok

90. Find the “Build” button again and click the arrow next to it

91. In the drop down menu click “Make All”

92. Wait for the console on the bottom to state "compilation finisheed"

93. Towards the top left, there should be a “Open” button with a picture of a folder, click on it

94. In the window that appears, on the left hand side, yet again find your (C:) drive and click on it

95. Find the “Project” folder and double click on it

96. Find the “AVC_robot” folder and double click on it

97. Find the “robot.cpp” file and click on it once

98. In the bottom right corner of the window, click open

99. In the same top bar that the “Open” button was located, find the “Build” button with a picture of a brick

100. Click on the arrow next to it

101. In the drop down menu click “Make All”

102. When the console log on the bottom says “Compilation Completed”, minimise Geany

103. Go back into the “Project” folder

104. Double click on “AVC_server”

105. Scroll down until you find “server3” application

106. Double click on it to open the maze window

107. Go back into the “AVC_server” window

108. Go back into the “Project” folder

109. Double click on “AVC_robot”

110. Double click on “robot” application

111. Find the server maze window that opened when you double clicked “server3” application, the robot should be traversing the maze

112. If you want to open a different maze, got back into the “Project” folder, and then double click on “AVC_server”

113. Find “config.txt” and double click it to open it in notepad

114. When notepad opens, the first line should say “mazeFile,core.txt”

115. To change to a completion, and then a challenge map, simply replace “core.txt” with “completion.txt”, or “challenge.txt”
Repeat steps 93 - 111
