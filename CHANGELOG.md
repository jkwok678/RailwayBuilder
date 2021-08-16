# Changelog

All notable changes to this project will be documented in this file.

## Core features - 14/08/2021

### Added
* The GUI for adding Element Block 2 (Includes implementation and documentation)
* Map class methods to store the Element Block 2 and 3 elements.

## Core features - 14/08/2021

### Added
* New button to change signal apsect in the program.
* Ability to add the signal track onto the screen.

## Core features - 11/08/2021

### Added
* Methods to draw Element Block 1 tracks (StraightTrack, DirectedTrack, CurvedTrack, LinkedTrack,
ExitTrack, BufferTrack, BridgeUnderpassTrack) SignalTrack has not been implemented yet. Waiting for another feature's completion.
* Methods to store Element block 1 tracks



## Core features - 11/08/2021

### Added
* Methods to calculate coordinates realtive to the map in the canvas class. (Includes implementaion and documentation)
* Implementation to the mousePressEvent and paintEvent overiding methods.
* Methods to allow straightH tracks to be added to screen.
* New method in map class to create and add straightTrack to storage.
### Changed
* The offsets X and Y now default at 0
* Changing offsets and clicking on canvas now updates the canvas.

## Core features - 10/08/2021

### Added
* 4 buttons in the right hand side menu.
* The buttons can change the offset X and Y in the canvas class.
* Methods to help change offsets.

### Changed
* The offsets X and Y now default at 0

## Core features - 06/08/2021

### Added
* The colour enum class.
* MousePressEvent and paintEvent methods to canvas class. (No implementation and documentation)

### Changed
* The elementChosen enum class is in elementChosen.h now.
* The mode enum class is in mode.h now.

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

## Start - 03/08/2021

### Added
* The CrossoverTrack class (includes implementaion and documentation)
* The CrossoverType enum class (includes implementaion and documentation)
* The FlyoverTrack class (includes implementaion and documentation)
* The FlyoverType enum class (includes implementaion and documentation)

## Start - 02/08/2021

### Added
* New methods to convert the distances and speed.

### Changed
* The methods that update the GUI to use the new methods.

## Start - 01/08/2021

### Changed
* The methods access modifiers from private to public for methods to convert distances and speed.


## Start - 29/07/2021

### Added
* Initial GUI to set and convert speeds and distances.
* Initial methods to update the GUI for converting speeds and distances based on user inputs.


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


## Start - 22/07/2021

### Added
* The ExitTrack class (includes implementaion and documentation)
* The ExitType enum class (includes implementaion and documentation)
* The BufferTrack class (includes implementaion and documentation)
* The BufferType enum class (includes implementaion and documentation)

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

## Changed
