# Changelog
    
All notable changes to this project will be documented in this file.
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
* The SwitchType enum clas (includes implementaion and documentation)
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
* The SignalType enum clas (includes implementaion and documentation)
* The BridgeUnderpassTrack class (includes implementaion and documentation)
* The BridgeUnderpassType enum clas (includes implementaion and documentation)


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
