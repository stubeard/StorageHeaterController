# StorageHeaterController
Demo project for a Storage Heater Controller

##Toolchain:

CMake 		Version: 3.15.5
MingGW-w64 	Version: 8.1.0,	Architecture: x64_86, Threads: posix, Exception: seh (Structured Exception Handling), Revision: 0

##Building

Open a windows console, change to the source code directory and type:
	
	mkdir build
	cd build
	cmake -G "MinGW Makefiles" ..
	mingw32-make

##Running

The application can be run by typing:

	StorageHeaterController.exe

##Testing

Tests have been provided which can be run by typing:

	ModelTest.exe
	ViewTest.exe

or by running:

	mingw32-make test

##Notes
ViewTest does not currently work with CTest. As it uses std::cin and std:cout, If this were a commercial project, I would create a test application to run ViewTest, feed it predefined strings and check it's output stream for the correct response. I would also add extra strings to the ModelTest application. Both test applications work well with manual input.


###Assumptions
The specification says that the schedule will be input for the following 24 hours, but does not say whether it should be synchronised with each half hour in the day e.g. (00:00, 00:30, 01:00, ... 23:30), I have decided to simply run the schedule starting from the time when it was input.
Each new schedule overwrites the previous one, even if it has not been completed.
On completing the schedule, the application will no longer output any changes, until a new schedule is input.

If this were a commercial project, I would query points these with the customer rather than make any assumptions.

Internally, the View class decodes the input string and sets a vector of bools containing the schedule which is passed to the Model. This was done to make it easier to abstract the view from the console.  

I also considered whether the View and Model should have their own threads for processing or whether this should be done in the Presentation Layer in a round robin way. This may have been simpler, but would have required use of the std::iostream::readsome() function to prevent the thread from blocking while waiting for input from std::cin. I decided to go with the multithreaded model as it made the View and Model self-contained, although both options are valid.


