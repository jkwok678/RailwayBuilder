#ifndef TRACK_H
#define TRACK_H
#include <QVariant>
#include <string>
#include <iostream>
#include "element.h"

/**
 * @brief The Platform enum.
 *
 * This enum is for the the platforms that can be placed on the side of the track.
 */
enum class Platform {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

/**
 * @brief The StraightType enum.
 *
 * This is for the 4 types of StraightTrack.
 */
enum class StraightType
{
	STRAIGHTH, /// Straight horizontal.
	STRAIGHTV, /// Straight vertical.
	STRAIGHTLEFTUP, /// Bottom right to top left straight.
	STRAIGHTRIGHTUP /// Bottom left to top right straight.
};




/**
 * @brief The DirectType enum.
 *
 * This is for the 8 different DirectedTrack types.
 */
enum class DirectedType
{
	DIRECTEDLEFT, /// Directed Track towards the left.
	DIRECTEDRIGHT, /// Directed Track towards the right.
	DIRECTEDUP, /// Directed Track upwards.
	DIRECTEDDOWN, /// Directed Track downwards.
	DIRECTEDRIGHTUP, /// Directed Track from the bottom left to the top right.
	DIRECTEDLEFTUP, /// Directed Track from the bottom right to the top left.
	DIRECTEDLEFTDOWN, /// Directed Track from the top right to the bottom left.
	DIRECTEDRIGHTDOWN /// Directed Track from the top left to the bottom right.
};




/**
 * @brief The CurvedType enum.
 *
 * This is for 12 Curves in total, four 90 degree turns and eight 135 degree turns.
 */
enum class CurvedType
{
	TIGHTCURVE1, /// 90 degree turn.
	TIGHTCURVE2, /// 90 degree turn.
	TIGHTCURVE3, /// 90 degree turn.
	TIGHTCURVE4, /// 90 degree turn.
	CURVE1, /// 135 degree turn.
	CURVE2, /// 135 degree turn.
	CURVE3, /// 135 degree turn.
	CURVE4, /// 135 degree turn.
	CURVE5, /// 135 degree turn.
	CURVE6, /// 135 degree turn.
	CURVE7, /// 135 degree turn.
	CURVE8  /// 135 degree turn.
};




/**
 * @brief The LinkedType enum.
 *
 * This is for 8 types of linked track, for 8 different directions of links.
 */
enum class LinkedType
{
	LINKLEFT, ///Link is on the left.
	LINKRIGHT, ///Link is on the right.
	LINKDOWN, ///Link is downwards
	LINKUP, ///Link is upwards.
	LINKLEFTUP, ///Link is top left.
	LINKRIGHTUP, ///Link is top right.
	LINKLEFTDOWN, ///Link is bottom left.
	LINKRIGHTDOWN ///Link is bottom right.
};




/**
 * @brief The ExitType enum.
 *
 * This is for 8 Exit tracks, for 8 directions of tracks.
 */
enum class ExitType
{
	EXITLEFT, /// Exit is on the left.
	EXITRIGHT, /// Exit is on the right.
	EXITDOWN, /// Exit is at the bottom.
	EXITUP, /// Exit is at the top.
	EXITLEFTUP, /// Exit is at the top left.
	EXITRIGHTUP, /// Exit is at the top right.
	EXITLEFTDOWN, /// Exit is at the bottom left.
	EXITRIGHTDOWN /// Exit is at the bottom right.
};




/**
 * @brief The BufferType enum.
 *
 * This is for the 8 different directions of the buffer.
 */
enum class BufferType
{
	BUFFERLEFT, /// Buffer is on the left.
	BUFFERRIGHT, /// Buffer is on the right.
	BUFFERDOWN, /// Buffer is at the bottom.
	BUFFERUP, /// Buffer is at the top.
	BUFFERLEFTUP, /// Buffer is at the top left.
	BUFFERRIGHTUP, /// Buffer is at the top right.
	BUFFERLEFTDOWN, /// Buffer is at the bottom left.
	BUFFERRIGHTDOWN /// Buffer is at the bottom right.
};




/**
 * @brief The SignalType enum.
 *
 * This is for the 8 directions of signals.
 */
enum class SignalType
{
	SIGNALLEFT, /// Signal to the left.
	SIGNALRIGHT, /// Signal to the right.
	SIGNALDOWN, /// Signal downwards.
	SIGNALUP, /// Signal upwards.
	SIGNALLEFTUP, /// Signal to the top left.
	SIGNALRIGHTUP, /// Signal to the top right.
	SIGNALLEFTDOWN, /// Signal to the bottom left.
	SIGNALRIGHTDOWN /// Signal to the bottom right.
};




/**
 * @brief The BridgeUnderpassType enum.
 *
 * This is for the 2 underpasses and 2 bridges.
 */
enum class BridgeUnderpassType
{
	BRIDGE1, /// Bridge is vertical.
	BRIDGE2, /// Bridge is horizontal.
	UNDERPASS1, /// Underpass is vertical.
	UNDERPASS2 /// Underpass is horizontal.
};




/**
 * @brief The SwitchType enum.
 *
 * There are 8 tight 90 degree switches.
 * There are also 8 switches that split off from the middle.
 * There are 16 normal 135 degree switches.
 */
enum class SwitchType
{
	SWITCHTIGHT1, /// 90 degree switch, from the left to the right and top.
	SWITCHTIGHT2, /// 90 degree switch, from the right to the left and top.
	SWITCHTIGHT3, /// 90 degree switch, from the left to the the right and bottom.
	SWITCHTIGHT4, /// 90 degree switch, from the right to the left and bottom.
	SWITCHTIGHT5, /// 90 degree switch, from the bottom to the left and top.
	SWITCHTIGHT6, /// 90 degree switch, from the bottom to the right and top.
	SWITCHTIGHT7, /// 90 degree switch, from the top to the left and bottom.
	SWITCHTIGHT8, /// 90 degree switch, from the top to the right and bottom.
	SWITCHSPLIT1, /// Split switch, from the left to the top right and bottom left.
	SWITCHSPLIT2, /// Split switch, from the right to the top left and bottom right.
	SWITCHSPLIT3, /// Split switch, from the top right to the bottom and the left.
	SWITCHSPLIT4, /// Split switch, from the bottom left to the top and right.
	SWITCHSPLIT5, /// Split switch, from the bottom right to the top and left.
	SWITCHSPLIT6, /// Split switch, from the top left to the bottom and right.
	SWITCHSPLIT7, /// Split switch, from the bottom to the top left and top right.
	SWITCHSPLIT8, /// Split switch, from the left to the top right and bottom left.
	SWITCH1, /// 135 degree switch, from the left to the right and top right.
	SWITCH2, /// 135 degree switch, from the right to the left and top left.
	SWITCH3, /// 135 degree switch, from the left to the right and bottom right.
	SWITCH4, /// 135 degree switch, from the right to the left and bottom left.
	SWITCH5, /// 135 degree switch, from the bottom to the top and top left.
	SWITCH6, /// 135 degree switch, from the bottom to the top and top right.
	SWITCH7, /// 135 degree switch, from the top to the bottom and bottom left.
	SWITCH8, /// 135 degree switch, from the top to the bottom and bottom right.
	SWITCH9, /// 135 degree switch, from the bottom right to the top left and top.
	SWITCH10, /// 135 degree switch, from the bottom left to the top right and top.
	SWITCH11, /// 135 degree switch, from the top right to the bottom left and bottom.
	SWITCH12, /// 135 degree switch, from the top left to the bottom right and bottom.
	SWITCH13, /// 135 degree switch, from the bottom right to the top left and left.
	SWITCH14, /// 135 degree switch, from the bottom left to the top right and right.
	SWITCH15, /// 135 degree switch, from the top right to the bottom left and left.
	SWITCH16 /// 135 degree switch, from the top left to the bottom right and right.
};



/**
 * @brief The CrossoverType enum
 *
 * There are 6 crossover tracks, where only 1 train is allowed at a time.
 */
enum class CrossoverType
{
	CROSSOVER1, /// Horizontal is main, vertical is secondary.
	CROSSOVER2, /// Top left to bottom right is main, bottom left to top right is secondary.
	CROSSOVER3, /// Vertical is main, other is secondary.
	CROSSOVER4, /// Vertical is main, other is secondary.
	CROSSOVER5, /// Horizontal is main, other is secondary.
	CROSSOVER6 /// Horizontal is main, other is secondary.
};




/**
 * @brief The FlyoverType enum
 *
 * There are 12 flyover tracks with 6 main ones. The other six are the same apart from having the other track on top instead.
 */
enum class FlyoverType
{
	FLYOVER1, /// The vertical track is the top track and the main track.
	FLYOVER2, /// The horizontal track is the top track and the main track.
	FLYOVER3, /// The top left to bottom right track is the top track and the main track.
	FLYOVER4, /// The top right to bottom left track is the top track and the main track.
	FLYOVER5, /// The vertical track is the top track and the main track.
	FLYOVER6, /// The vertical track is the top track and the main track.
	FLYOVER7, /// The top left to bottom right track is the top track and the main track.
	FLYOVER8, /// The top right to bottom left track is the top track and the main track.
	FLYOVER9, /// The horizontal track is the top track and the main track.
	FLYOVER10, /// The horizontal track is the top track and the main track.
	FLYOVER11, /// The top left to bottom right track is the top track and the main track.
	FLYOVER12 /// The top right to bottom left track is the top track and the main track.
};




/**
 * @brief The Track class.
 *
 * This class is the foundation for other track types like StraightTrack or CurvedTrack.
 *
 * @version 0.1
 * @author Jonathan Kwok
 */
class Track : public NamedElement
{
private:
	/**
	 * @brief Gets the track's main speed as a QString
	 * @return Track's main speed as QString
	 */
	QString getTrackMainSpeedToQString();

	/**
	 * @brief Gets the track's main length as a QString
	 * @return Track's main length as QString
	 */
	QString getTrackMainLengthToQString();

	/**
	 * @brief Gets the track's secondary speed as a QString
	 * @return Track's secondary speed as QString
	 */
	QString getTrackSecondarySpeedToQString();

	/**
	 * @brief Gets the track's secondary length as a QString
	 * @return Track's secondary length as QString
	 */
	QString getTrackSecondaryLengthToQString();


protected:
	int trackMainSpeed{ 200 };
	int trackMainLength{ 100 };
	int trackSecondarySpeed{-1};
	int trackSecondaryLength{-1};
	bool links [9]{false, false, false, false, false, false, false, false, false};
	std::shared_ptr<NamedLocation> linkedNamedLocation;
	bool found;


	/**
	 * @brief Sets the default secondary speed and length.
	 */
	void setDefaultSecondarySpeedLength();

public:

	/**
	 * @brief A default constructor for the Track class.
	 */
	Track();

	/**
	 * @brief Gets the main speed of the track.
	 * @return An int that is the speed of the track.
	 */
	int getTrackMainSpeed() const;

	/**
	 * @brief Sets the main speed of the track.
	 * @param speed The new main speed.
	 */
	void setTrackMainSpeed(int speed);

	/**
	 * @brief Gets the main track length.
	 * @return An int that is the length of the track.
	 */
	int getTrackMainLength() const;

	/**
	 * @brief Sets the main track length.
	 * @param speed The new main track length.
	 */
	void setTrackMainLength(int length);

	/**
	 * @brief Gets the secondary speed of the track.
	 * @return An int that is the secondary speed of the track.
	 */
	int getTrackSecondarySpeed() const;

	/**
	 * @brief Sets the secondary speed of the track.
	 * @param speed The new secondary speed.
	 */
	void setTrackSecondarySpeed(int speed);

	/**
	 * @brief Gets the secondary track length.
	 * @return An int that is the secondary length of the track.
	 */
	int getTrackSecondaryLength() const;

	/**
	 * @brief Sets the secondary track length.
	 * @param speed The new secondary track length.
	 */
	void setTrackSecondaryLength(int length);

	/**
	 * @brief Gets the track's main speed and length as a QString
	 * @return QString main speed and length
	 */
	QString mainSpeedLengthToQString();

	/**
	 * @brief Gets the track's main speed and length as a QString
	 * @return QString secondary speed and length
	 */
	QString secondarySpeedLengthToQString();

	/**
	 * @brief Gets whether there is a link a location on track.
	 *
	 * A track has 8 possible locations to link from.
	 * 0 1 2
	 * 3 4 5
	 * 6 7 8
	 * The links are 0, 1, 2, 3, 5, 6, 7, 8.
	 * 4 is not used.
	 * Example 1.  '-' is a straight horizontal with 3 and 5 as it's links.
	 * Example 2. '/' is a bottom left to top right track with links at 2 and 6.
	 *
	 * @param link The link you want to check to see if there is something connected there.
	 * @return A bool that describes if there is a track at that link.
	 */
	bool getLinkAt(int link);

	/**
	 * @brief Get the NamedLocation that is at this track.
	 * @return A NamedLocation.
	 */
	std::shared_ptr<NamedLocation> getNamedLocation();

	/**
	 * @brief Set the NamedLocation at this track.
	 */
	void setNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation);

	/**
	 * @brief Checks if the track has been found yet.
	 *
	 * Useful for searches for that they don't get stuck in loops.
	 * @return True if it has been found by a search before, false if not.
	 */
	bool getFound() const;

	/**
	 * @brief Sets the track to found.
	 *
	 * Useful for searches for that they don't get stuck in loops.
	 * Needs to be reset to false after search is done.
	 * @param newFound True if it's found by a search, false to reset after a search.
	 */
	void setFound(bool newFound);

	/**
	 * @brief A method to convert a Track to a QString.
	 * @return QString representation of a Track.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a Track to a QString for file saving.
	 * @return QString representation of a Track to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The StraightTrack class.
 *
 * This inehrits from the track class.
 * It can contain platforms or level crossings.
 * Only main speed and length matter as there are only 2 endings.
 *
 * @version 0.1
 * @author Jonathan Kwok
 */
class StraightTrack : public Track
{
private:
	StraightType straightType;
	bool levelCrossing{ false };

    /**
     * @brief Gets if the track has a platform1 as a QString
     * @return '1' if track has a platform1 otherwise '0'.
     */
    QString getPlatform1ToQString();

    /**
     * @brief Gets if the track has a platform2 as a QString
     * @return '1' if track has a platform2 otherwise '0'
     */
    QString getPlatform2ToQString();


protected:
	//For vertical tracks, platform1 is left, platform2 is right
	//For Horizontal tracks platform1 is up, platform2 is down
	bool platform1{ false };
	bool platform2{ false };


public:

	/**
	 * @brief Default constructor for StraightTrack.
	 */
	StraightTrack();
	/**
	 * @brief A StraightTrack constructor needs it's location and Straight track type.
	 * @param newStraightType The Straight track type.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	StraightTrack(StraightType newStraightType, int newLocationX, int newLocationY);

	/**
	 * @brief Gets the StraightType enum.
	 * @return The StraightType enum.
	 */
	StraightType getStraightType() const;

	/**
	 * @brief Sets the new Straight track type.
	 * @param newStraightType The new Straight track enum.
	 */
	void setStraightType(const StraightType &newStraightType);

	/**
	 * @brief Checks if the track has a platform
	 * @return True if there is a platform otherwise false
	 */
	bool hasPlatform() const;

	/**
	 * @brief Checks if the platform is on the left of the track or or above the track if it's sideways.
	 * @return A bool saying if there is a platform on the left of the track or above the track if it's sideways.
	 */
	bool getPlatform1() const;

	/**
	 * @brief Sets whether there is a platform on the left of the track or above the track if it's sideways.
	 * @param newPlatform If this is true, there is a platform on the left of the track or above the track if it's sideways.
	 */
	void setPlatform1(bool newPlatform);

	/**
	 * @brief Checks if there is a platform on the right of the track or below the track if it's sideways.
	 * @return A bool saying if there is a platform on the right of the track or or below the track if it's sideways.
	 */
	bool getPlatform2() const;

	/**
	 * @brief Sets whether there is a platform on the right of the track or below the track if it's sideways.
	 * @param newPlatform If this is true there is a platform on the right of the track or below the track if it's sideways.
	 */
	void setPlatform2(bool newPlatform);

    /**
     * @brief Gets the platforms as a QString.
     *
     * 1,1 = track has platform 1 & 2
     * 1,0 = track has paltform 1 only
     * 0,1 = track has platform 2 only
     * 0,0 = track has no platforms.
     * @return QString representation of the status of the platforms.
     */
    QString platformsToQString();

	/**
	 * @brief Checks if the track has a level crossing.
	 * @return A bool saying if it has a level crossing.
	 */
	bool hasLevelCrossing() const;

	/**
	 * @brief Adds a level crossing to this track..
	 */
	void addLevelCrossing();

	/**
	 * @brief Removes a level crossing from this track.
	 */
	void removeLevelCrossing();

	/**
	 * @brief Gets if there is a level crossing as a QString.
	 * @return QString "1" if there is a level crossing otherwise "0".
	 */
	QString levelCrossingToQString();

	/**
	 * @brief Converts StraightType to QString.
	 * @return QString that is the StraightType.
	 */
	QString straightTypeToQString();

	/**
	 * @brief A method to convert a straightTrack to a QString.
	 * @return QString representation of a StraightTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a StraightTrack to a QString for file saving.
	 * @return QString representation of a StraightTrack to be written to file.
	 */
	QString toQStringForSave();


};




/**
 * @brief The DirectedTrack class.
 *
 * This inehrits from the Straight Track class.
 * It can contain platforms or level crossings.
 * Only main speed and length matter as there are only 2 endings.
 *
 * @version 0.1
 * @author Jonathan Kwok
 */
class DirectedTrack : public StraightTrack
{
private:
	DirectedType directedType;



protected:


public:

	/**
	 * @brief The DirectedTrack constructor that needs its location and it's type of DirectedTrack type.
	 * @param newDirectedType The DirectedTrack type.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	DirectedTrack(DirectedType newDirectedType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of DirectedTrack.
	 * @return The DirectedType enum.
	 */
	DirectedType getDirectType() const;

	/**
	 * @brief Set the type of DirectedTrack.
	 * @param newDirectedType The new DirectedType enum.
	 */
	void setDirectedType(const DirectedType &newDirectedType);

	/**
	 * @brief Converts DirectedType to QString.
	 * @return QString that is the DirectedType.
	 */
	QString directedTypeToQString();

	/**
	 * @brief A method to convert a DirectedTrack to a QString.
	 * @return QString representation of a DirectedTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a DirectedTrack to a QString for file saving.
	 * @return QString representation of a DirectedTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The CurvedTrack class.
 *
 * This inehrits from the Track class.
 * It cannot have platforms and level crossings.
 * Only main speed and length matter as there are only 2 endings.
 *
 * @version 0.1
 * @author Jonathan Kwok
 */
class CurvedTrack : public Track
{
private:
	CurvedType curvedType;



protected:


public:

	/**
	 * @brief A CurvedTrack constructor that needs its location and its CurveType.
	 * @param newCurvedType The CurveType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y corrdinate of the track.
	 */
	CurvedTrack(CurvedType newCurvedType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of CurvedTrack.
	 * @return The CurvedType enum.
	 */
	CurvedType getCurvedType() const;

	/**
	 * @brief Set the type of CurvedTrack.
	 * @param newCurvedType The CurvedType enum.
	 */
	void setCurvedType(const CurvedType &newCurvedType);

	/**
	 * @brief Converts CurvedType to QString.
	 * @return QString that is the CurvedType.
	 */
	QString curvedTypeToQString();

	/**
	 * @brief A method to convert a curvedTrack to a QString.
	 * @return QString representation of a CurvedTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a CurvedTrack to a QString for file saving.
	 * @return QString representation of a CurvedTrack to be written to file.
	 */
	QString toQStringForSave();


};




/**
 * @brief The LinkedTrack class.
 *
 * This inehrits from the Track class.
 * It cannot have platforms and level crossings.
 * Only main speed and length matter as there are only 2 endings.
 *
 * @version 0.1
 * @author Jonathan Kwok
 */
class LinkedTrack : public Track
{
private:
	LinkedType linkedType;
	std::shared_ptr<LinkedTrack> otherLinkTrack{nullptr};



protected:


public:

	/**
	 * @brief Default LinkedTrack constructor.
	 */
	LinkedTrack();

	/**
	 * @brief A LinkedTrack constructor that needs its location and its LinkType.
	 * @param newLinkedType The LinkType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	LinkedTrack(LinkedType newLinkedType, int newLocationX, int newLocationY);

	/**
	 * @brief Get type of LinkedTrack.
	 * @return The LinkedType enum.
	 */
	LinkedType getLinkedType() const;

	/**
	 * @brief set the type of LinkeTrack.
	 * @param newLinkedType The LinkedType enum.
	 */
	void setLinkedType(const LinkedType &newLinkedType);

	/**
	 * @brief Checks if the LinkedTrack is linked to another LinkedTrack.
	 * @return true if it's linked otherwise false.
	 */
	bool isLinked() const;

	/**
	 * @brief Get the linked track.
	 * @return A shared pointer that contains another LinkedTrack.
	 */
	std::shared_ptr<LinkedTrack> getOtherLinkedTrack();

	/**
	 * @brief Set the linked track to another LinkedTrack.
	 * @param newLinkedTrack A shared pointer that has a LinkedTrack.
	 */
	void setOtherLinkedTrack(std::shared_ptr<LinkedTrack> &newLinkedTrack);

	/**
	 * @brief Removes the other Linked Track.
	 */
	void removeOtherLinkedTrack();

	/**
	 * @brief Converts LinkedType to QString.
	 * @return QString that is the LinkedType.
	 */
	QString linkedTypeToQString();

	/**
	 * @brief A method to convert a linkedTrack to a QString.
	 * @return QString representation of a LinkedTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert the other linkedTrack to a QString.
	 * @return QString representation of the other LinkedTrack.
	 */
	QString otherLinkedTrackToQString();

	/**
	 * @brief A method to convert a LinkedTrack to a QString for file saving.
	 * @return QString representation of a LinkedTrack to be written to file.
	 */
	QString toQStringForSave();

	/**
	 * @brief A method to convert the other LinkedTrack to a QString for file saving.
	 * @return QString representation of the other LinkedTrack to be written to file.
	 */
	QString otherLinkedTrackToQStringForSave();
};




/**
 * @brief The ExitTrack class.
 *
 * This inehrits from the Track class.
 * It cannot have platforms and level crossings.
 * Only main speed and length matter as there are only 2 endings.
 *
 * @version 0.1
 * @author Jonathan Kwok
 */
class ExitTrack : public Track
{
private:
	ExitType exitType;



protected:


public:

	/**
	 * @brief An ExitTrack constructor that needs its location and its ExitType.
	 * @param newExitType The ExitType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	ExitTrack(ExitType newExitType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of ExitTrack.
	 * @return The ExitType enum.
	 */
	ExitType getExitType() const;

	/**
	 * @brief Set the type of ExitTrack.
	 * @param newExitType The new ExitType enum.
	 */
	void setExitType(const ExitType &newExitType);

	/**
	 * @brief Converts ExitType to QString.
	 * @return QString that is the ExitType.
	 */
	QString exitTypeToQString();

	/**
	 * @brief A method to convert a ExitTrack to a QString.
	 * @return QString representation of a ExitTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a ExitTrack to a QString for file saving.
	 * @return QString representation of a ExitTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The BufferTrack class.
 *
 * This inehrits from the StraightTrack class.
 * It can have platforms but not level crossings (Theorecically it can hold levelcrossings but it shouldn't ever).
 * Only main speed and length matter as there are only 2 endings.
 *
 * @warning Since it inherits StraightTrack, it can have level crossings, but it should never have it. This should be made impossible by other classes.
 * @version 0.1
 * @author Jonathan Kwok
 */
class BufferTrack : public StraightTrack
{
private:
	BufferType bufferType;



protected:


public:

	/**
	 * @brief A BufferTrack constructor that needs its location and its BufferType.
	 * @param newBufferType The BufferType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	BufferTrack(BufferType newBufferType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of BufferTrack.
	 * @return The BufferType enum.
	 */
	BufferType getBufferType() const;

	/**
	 * @brief Set the type of BufferTRack.
	 * @param newBufferType The new BufferType enum.
	 */
	void setBufferType(const BufferType &newBufferType);

	/**
	 * @brief Converts BufferType to QString.
	 * @return QString that is the BufferType.
	 */
	QString bufferTypeToQString();

	/**
	 * @brief A method to convert a BufferTrack to a QString.
	 * @return QString representation of a BufferTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a BufferTrack to a QString for file saving.
	 * @return QString representation of a BufferTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The SignalTrack class.
 *
 * This inehrits from the StraightTrack class.
 * It can have platforms but not level crossings (Theorecically it can hold levelcrossings but it shouldn't ever).
 * Only main speed and length matter as there are only 2 endings.
 *
 * @warning Since it inherits StraightTrack, it can have level crossings, but it should never have it. This should be made impossible by other classes.
 * @version 0.1
 * @author Jonathan Kwok
 */
class SignalTrack : public StraightTrack
{
private:
	SignalType signalType;
	int aspect;




protected:


public:

	/**
	 * @brief A SignalTrack constructor that needs its location, signalType and its aspect.
	 * @param newSignalType The SignalType.
	 * @param newAspect The number of signal aspects there are.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	SignalTrack(SignalType newSignalType, int newAspect, int newLocationX, int newLocationY);

	/**
	 * @brief Get the number of aspects the signal has.
	 * @return THe number of aspects on this signal.
	 */
	int getAspect() const;

	/**
	 * @brief Set the number of aspects the signal has.
	 * @param newAspect The new number of aspects on the signal.
	 */
	void setAspect(int newAspect);

	/**
	 * @brief Gets the Signal aspect as a QString.
	 * @return QString signal aspect.
	 */
	QString aspectToQString();

	/**
	 * @brief Get the type of SignalType.
	 * @return  The SignalType enum.
	 */
	SignalType getSignalType() const;

	/**
	 * @brief Set the type of SignalType.
	 * @param newSignalType The new SignalType enum.
	 */
	void setSignalType(const SignalType &newSignalType);

	/**
	 * @brief Converts SignalType to QString.
	 * @return QString that is the SignalType.
	 */
	QString signalTypeToQString();

	/**
	 * @brief A method to convert a SignalTrack to a QString.
	 * @return QString representation of a SignalTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a SignalTrack to a QString for file saving.
	 * @return QString representation of a SignalTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The BridgeUnderpassTrack class.
 *
 * This inehrits from the StraightTrack class.
 * It can have platforms but not level crossings (Theorecically it can hold levelcrossings but it shouldn't ever).
 * Only main speed and length matter as there are only 2 endings.
 *
 * @warning Since it inherits StraightTrack, it can have level crossings, but it should never have it. This should be made impossible by other classes.
 * @version 0.1
 * @author Jonathan Kwok
 */
class BridgeUnderpassTrack : public StraightTrack
{
private:
	BridgeUnderpassType bridgeUnderpassType;



protected:


public:

	/**
	 * @brief A BridgeUnderpassTrack constructor that needs its location and its bridge or underpass type.
	 * @param newBridgeUnderpassType The BridgeUnderpassType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	BridgeUnderpassTrack(BridgeUnderpassType newBridgeUnderpassType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of BridgeUnderpassType.
	 * @return The BridgeUnderpassType enum.
	 */
	BridgeUnderpassType getBridgeUnderpassType() const;

	/**
	 * @brief Set the type of BridgeUnderpassType.
	 * @param newBridgeUnderpassType The new BridgeUnderpassType enum.
	 */
	void setBridgeUnderpassType(const BridgeUnderpassType &newBridgeUnderpassType);

	/**
	 * @brief Converts BridgeUnderpassType to QString.
	 * @return QString that is the BridgeUnderpassType.
	 */
	QString bridgeUnderpassTypeToQString();

	/**
	 * @brief A method to convert a BridgeUnderpassTrack to a QString.
	 * @return QString representation of a BridgeUnderpassTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a BridgeUnderpassTrack to a QString for file saving.
	 * @return QString representation of a BridgeUnderpassTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The SwitchTrack class.
 *
 * This inehrits from the StraightTrack class.
 * It can have platforms but not level crossings (Theorecically it can hold levelcrossings but it shouldn't ever).
 * Both main and secondary speed and length matter as there are 3 endings.
 * Secondary speeds and length are for the diverging track if there is one.
 * Otherwise main speeds and lengths are the left track and the right track is the secondary.
 *
 * @warning Since it inherits StraightTrack, it can have level crossings, but it should never have it. This should be made impossible by other classes.
 * @warning It can only have a platform on the straight track of the switch.
 * @version 0.1
 * @author Jonathan Kwok
 */
class SwitchTrack : public StraightTrack
{
private:
	SwitchType switchType;



protected:


public:

	/**
	 * @brief A SwitchTrack constructor that needs its location and switch type.
	 * @param newSwitchType The Switchtype.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	SwitchTrack(SwitchType newSwitchType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of SwitchType.
	 * @return The SwitchType enum.
	 */
	SwitchType getSwitchType() const;

	/**
	 * @brief Set the type of SwitchType.
	 * @param newSwitchType The new SwitchType enum.
	 */
	void setSwitchType(const SwitchType &newSwitchType);

	/**
	 * @brief Converts SwitchType to QString.
	 * @return QString that is the SwitchType.
	 */
	QString switchTypeToQString();

	/**
	 * @brief A method to convert a SwitchTrack to a QString.
	 * @return QString representation of a SwitchTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a SwitchTrack to a QString for file saving.
	 * @return QString representation of a SwitchTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The CrossoverTrack class
 *
 * This inehrits from the Track class.
 * It cannot have platforms and level crossings.
 * Both main and secondary speed and length matter as there are 4 endings.
 *
 * Main speed and lengths are for horizontal and vertical tracks, when there is a diagonal.
 * When it's just horizontal and vertical, horizontal is main and secondary is vertical.
 * For an X shaped track, top left to bottom right is the main and the other is secondary.
 * @version 0.1
 * @author Jonathan Kwok
 */
class CrossoverTrack : public Track
{
private:
	CrossoverType crossoverType;



protected:


public:

	/**
	 * @brief A CrossoverTrack constructor that needs its location and crossover type.
	 * @param newCrossoverType The CrossoverType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	CrossoverTrack(CrossoverType newCrossoverType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of CrossoverType.
	 * @return The CrossoverType enum.
	 */
	CrossoverType getCrossoverType() const;

	/**
	 * @brief Set the type of CroosoverType.
	 * @param newCrossoverType The new CrossoverType enum.
	 */
	void setCrossoverType(const CrossoverType &newCrossoverType);

	/**
	 * @brief Converts CrossoverType to QString.
	 * @return QString that is the CrossoverType.
	 */
	QString crossoverTypeToQString();

	/**
	 * @brief A method to convert a CrossoverTrack to a QString.
	 * @return QString representation of a CrossoverTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a CrossoverTrack to a QString for file saving.
	 * @return QString representation of a CrossoverTrack to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The FlyoverTrack class
 *
 * This inehrits from the Track class.
 * It cannot have platforms and level crossings.
 * Both main and secondary speed and length matter as there are 4 endings.
 * @version 0.1
 * @author Jonathan Kwok
 */
class FlyoverTrack : public Track
{
private:
	FlyoverType flyoverType;



protected:


public:

	/**
	 * @brief A FlyoverTrack constructor that needs its location and flyover type.
	 * @param newFlyoverType The FlyoverType.
	 * @param newLocationX X coordinate of the track.
	 * @param newLocationY Y coordinate of the track.
	 */
	FlyoverTrack(FlyoverType newFlyoverType, int newLocationX, int newLocationY);

	/**
	 * @brief Get the type of FlyoverTrack.
	 * @return The FlyoverType enum.
	 */
	FlyoverType getFlyoverType() const;

	/**
	 * @brief Set the type of FlyoverType.
	 * @param newFlyoverType The new FLyoverType enum
	 */
	void setFlyoverType(const FlyoverType &newFlyoverType);

	/**
	 * @brief Converts FlyoverType to QString.
	 * @return QString that is the FlyoverType.
	 */
	QString flyoverTypeToQString();

	/**
	 * @brief A method to convert a FlyoverTrack to a QString.
	 * @return QString representation of a FlyoverTrack.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a FLyoverTrack to a QString for file saving.
	 * @return QString representation of a FlyoverTrack to be written to file.
	 */
	QString toQStringForSave();
};
#endif // TRACK_H
