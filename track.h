#ifndef TRACK_H
#define TRACK_H
#include <string>
#include <iostream>
#include "element.h"

class Track : public NamedElement
{
private:


protected:
	int trackMainSpeed{ 200 };
	int trackMainLength{ 100 };
	int trackSecondarySpeed{-1};
	int trackSecondaryLength{-1};
	//For vertical tracks, platform1 is left, platform2 is right
	//For Horizontal tracks platform1 is up, platform2 is down
	bool platformAny{ false };
	bool platform1{ false };
	bool platform2{ false };
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
	 * @brief Gets whether there is a link a location on track
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
	 *
	 * @return true if it has been found by a search before, false if not.
	 */
	bool getFound() const;
	/**
	 * @brief Sets the track to found.
	 *
	 * Useful for searches for that they don't get stuck in loops.
	 * Needs to be reset to false after search is done.
	 *
	 * @param newFound true if it's found by a search, false to reset after a search
	 */
	void setFound(bool newFound);
};

#endif // TRACK_H
