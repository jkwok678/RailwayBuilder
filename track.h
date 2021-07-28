#ifndef TRACK_H
#define TRACK_H
#include <string>
#include <iostream>
#include "element.h"




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
	STRIAGHTRIGHTUP /// Bottom left to top right straight.
};




/**
 * @brief The DirectType enum.
 *
 * This is for the 8 different DirectedTrack types.
 */
enum class DirectedType
{
	DIRECTLEFT, /// Directed Track towards the left.
	DIRECTRIGHT, /// Directed Track towards the right.
	DIRECTUP, /// Directed Track upwards.
	DIRECTDOWN, /// Directed Track downwards.
	DIRECTRIGHTUP, /// Directed Track from the bottom left to the top right.
	DIRECTLEFTUP, /// Directed Track from the bottom right to the top left.
	DIRECTLEFTDOWN, /// Directed Track from the top right to the bottom left.
	DIRECTRIGHTDOWN /// Directed Track from the top left to the bottom right.
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



protected:
	int trackMainSpeed{ 200 };
	int trackMainLength{ 100 };
	int trackSecondarySpeed{-1};
	int trackSecondaryLength{-1};
	bool links [9]{false, false, false, false, false, false, false, false, false};
	bool found;

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
	//For vertical tracks, platform1 is left, platform2 is right
	//For Horizontal tracks platform1 is up, platform2 is down
	bool platformAny{ false };
	bool platform1{ false };
	bool platform2{ false };
	bool levelCrossing{ false };

protected:



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
	 * @return The new Straight track enum.
	 */
	StraightType getStraightType() const;

	/**
	 * @brief Sets the new Straight track type.
	 * @param newStraightType The new Straight track enum.
	 */
	void setStraightType(const StraightType &newStraightType);

	/**
	 * @brief Gets whether this track has a platform attached to it.
	 * @return bool that represents whether this track has a platform.
	 */
	bool getPlatformAny() const;

	/**
	 * @brief Sets whether this track has a platform attached to it.
	 * @param platform Bool with platform or not.
	 */
	void setPlatformAny(bool platform);

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
	 * @brief Checks if the track has a level crossing.
	 * @return A bool saying if it has a level crossing.
	 */
	bool hasLevelCrossing() const;

	/**
	 * @brief Adds a level crossing to the current track.
	 */
	void addLevelCrossing();

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
	bool linked;
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
	 * @brief Checks if the track is linked to another linked track.
	 * @return A bool, true if it is linked and false if its not.
	 */
	bool getLinked() const;

	/**
	 * @brief Set whether the track is linked.
	 * @param newLinked A bool that says if the track is linked.
	 */
	void setLinked(bool newLinked);

	/**
	 * @brief Get the linked track.
	 * @return A shared pointer that contains another LinkedTrack.
	 */
	std::shared_ptr<LinkedTrack> getOtherLinkTrack();
	/**
	 * @brief Set the linked track to another LinkedTrack.
	 * @param newLinkedTrack A shared pointer that has a LinkedTrack.
	 */
	void setOtherLinkTrack(std::shared_ptr<LinkedTrack> &newLinkedTrack);
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
	 * @brief Get the type of SignalType.
	 * @return  The SignalType enum.
	 */
	SignalType getSignalType() const;
	/**
	 * @brief Set the type of SignalType.
	 * @param newSignalType The new SignalType enum.
	 */
	void setSignalType(const SignalType &newSignalType);
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
};
#endif // TRACK_H
