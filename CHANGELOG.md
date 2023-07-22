# Changelog

All notable changes to this project will be documented in this file.

## Core features - 09/01/2022

### Added
* Doxygen version updated to now use 1.9.2
* Doxygen CSS added as a submodule as well.

### Changed

### Fixed

## Core features - 23/12/2021

### Added
* Automated tests for some classes using Google test.

### Changed

### Fixed


## Core features - 16/11/2021

### Added

### Changed

### Fixed
* A bug that stopped the text from changing colour when the the background colour changed.


## Core features - 20/09/2021

### Added
* The ability to change the font of future text.

### Changed

### Fixed


## Core features - 19/09/2021

### Added
* The ability to name NamedElements.

### Changed

### Fixed


## Core features - 16/09/2021

### Added
* The ability to move text to the canvas.

### Changed
* The behaviour of adding text to screen with the pop up box.(Cancel button now leaves the text without editing it.)

### Fixed


## Core features - 15/09/2021

### Added
* The ability to add text to the canvas.

### Changed

### Fixed


## Core features - 14/09/2021

### Added
* The ability to check if the system is completely connected.

### Changed

### Fixed


## Core features - 03/09/2021

### Added
* The ability to connect LinkedTracks together.
* The ability to change the connections of LinkedTracks. 

### Changed

### Fixed


## Core features - 29/08/2021

### Added

### Changed
* The location of the toggle grid button

### Fixed


## Core features - 25/08/2021

### Added
* A grid feature to the canvas( The user can toggle the Grid ON and OFF)

### Changed

### Fixed


## Core features - 25/08/2021

### Added
* A feature that allows the user to change the background of the canvas.

### Changed

### Fixed


## Core features - 25/08/2021

### Added
* The GUI is able to add everything to the screen.


### Changed

### Fixed


## Core features - 22/08/2021

### Added
* The GUI for adding Element Block 4,5 (Includes implementation and documentation)
* The methods for adding Element Block 4,5 to the screen (Includes implementation and documentation)
* Everything can now be drawn on screen apart from the level crossing.

### Changed

### Fixed
* A bug that messed up some button placements in the elementMenu.

## Core features - 19/08/2021

### Added
* The GUI for adding Element Block 3 (Includes implementation and documentation)
* The methods for adding Element Block 3 to the screen (Includes implementation and documentation)

### Changed

### Fixed


## Core features - 14/08/2021

### Added
* The GUI for adding Element Block 2 (Includes implementation and documentation)
* Map class methods to store the Element Block 2 and 3 elements.

### Changed

### Fixed


## Core features - 14/08/2021

### Added
* New button to change signal apsect in the program.
* Ability to add the signal track onto the screen.

### Changed

### Fixed


## Core features - 11/08/2021

### Added
* Methods to draw Element Block 1 tracks (StraightTrack, DirectedTrack, CurvedTrack, LinkedTrack,
ExitTrack, BufferTrack, BridgeUnderpassTrack) SignalTrack has not been implemented yet. Waiting for another feature's completion.
* Methods to store Element block 1 tracks

### Changed

### Fixed


## Core features - 11/08/2021

### Added
* Methods to calculate coordinates realtive to the map in the canvas class. (Includes implementaion and documentation)
* Implementation to the mousePressEvent and paintEvent overiding methods.
* Methods to allow straightH tracks to be added to screen.
* New method in map class to create and add straightTrack to storage.
### Changed
* The offsets X and Y now default at 0
* Changing offsets and clicking on canvas now updates the canvas.

### Fixed


## Core features - 10/08/2021

### Added
* 4 buttons in the right hand side menu.
* The buttons can change the offset X and Y in the canvas class.
* Methods to help change offsets.

### Changed
* The offsets X and Y now default at 0
### Fixed


## Core features - 06/08/2021

### Added
* The colour enum class.
* MousePressEvent and paintEvent methods to canvas class. (No implementation and documentation)

### Changed
* The elementChosen enum class is in elementChosen.h now.
* The mode enum class is in mode.h now.

### Fixed


## Start - 04/08/2021

### Added
* The NamedLocation class (includes implementaion and documentation)
* The Concourse class (includes implementaion and documentation)
* The Parapet class (includes implementaion and documentation)
* The ParapetType enum class (includes implementaion and documentation)
* Added the map class
* Methods to check number of tracks and to check if an element exists at a coordiante.
* Methods to work with StraightTracks in the map class E.g. getStraightTrackAt() and addStraightTrack().

### Changed
* The layout of the element.h and element.cpp files to be clearer.

### Fixed


## Start - 03/08/2021

### Added
* The CrossoverTrack class (includes implementaion and documentation)
* The CrossoverType enum class (includes implementaion and documentation)
* The FlyoverTrack class (includes implementaion and documentation)
* The FlyoverType enum class (includes implementaion and documentation)

### Changed

### Fixed


## Start - 02/08/2021

### Added
* New methods to convert the distances and speed.

### Changed
* The methods that update the GUI to use the new methods.

## Start - 01/08/2021

### Changed

### Changed
* The methods access modifiers from private to public for methods to convert distances and speed.

### Fixed


## Start - 29/07/2021

### Added
* Initial GUI to set and convert speeds and distances.
* Initial methods to update the GUI for converting speeds and distances based on user inputs.

### Changed

### Fixed


## Start - 28/07/2021

### Added
* The SwitchTrack class (includes implementaion and documentation)
* The SwitchType enum class (includes implementaion and documentation)
* New GUI frontend elements to set/convert speeds and distances.
* New backend signal slots to set/convert speeds and distances.
* New methods to convert distances and speeds

### Changed
* The private slot methods for updating GUI when converting speed and distance.(They just use the new methods and update the GUI now)

### Fixed
* Some grammar on the documentation in the track.h file.
* resources.qrc is now in the CMakeList.txt file.


## Start - 25/07/2021

### Added
* The SignalTrack class (includes implementaion and documentation)
* The SignalType enum class (includes implementaion and documentation)
* The BridgeUnderpassTrack class (includes implementaion and documentation)
* The BridgeUnderpassType enum class (includes implementaion and documentation)

### Changed

### Fixed


## Start - 22/07/2021

### Added
* The ExitTrack class (includes implementaion and documentation)
* The ExitType enum class (includes implementaion and documentation)
* The BufferTrack class (includes implementaion and documentation)
* The BufferType enum class (includes implementaion and documentation)

### Changed

### Fixed
* Images now added to the project. Along with the resources.qrc file.
* Some grammatical errors in the Doxygen comments in the track.h file.


## Start - 22/07/2021

### Added
* The CurvedTrack class (includes implementaion and documentation)
* The LinkedTrack class (includes implementaion and documentation)
* The CurvedType enum class (includes implementaion and documentation)
* The DirectedType enum class (includes implementaion and documentation)
* *.txt.user to gitignore.

### Changed
* Location of platformAny variable, and methods that use it from the Track class to the StraightTrack class.
* Location of paltform1 variable, and methods that use it from the Track class to the StraightTrack class.
* Location of platform2 variable, and methods that use it from the Track class to the StraightTrack class.
* Spacing of code to make it less cluttered.
* 
### Fixed


## Start - 21/07/2021

### Added
* Images and the resources.qrc
* Image files loading
* Cmake
* The boardlayout class (includes implementaion)
* The ElementChosen enum class
* The Mode enum class
* The Canvas class (includes implementaion and documentation)
* The Window class (includes implementaion and documentation)
* The Element class (includes implementaion and documentation)
* The Text class (includes implementaion and documentation)
* The NamedElement class (includes implementaion and documentation)
* The Track class (includes implementaion and documentation)
* The StraightTrack class (includes implementaion and documentation)
* The DirectedTrack class (includes implementaion and documentation)
* The StraightType enum class (includes implementaion and documentation)
* The DirectedType enum class (includes implementaion and documentation)
* Initial GUI (One button)

### Changed

### Fixed

