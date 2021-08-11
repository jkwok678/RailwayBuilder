#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include <QMessageBox>
#include "element.h"
#include "track.h"

/**
 * @brief The Map class
 *
 * This class is my data structure for storing all the content that the user adds to the screen.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Map
{
private:
	int totalTrack{0};

	std::vector<std::shared_ptr<StraightTrack>> straightTrackList;
	std::vector<std::shared_ptr<DirectedTrack>> directTrackList;
	std::vector<std::shared_ptr<CurvedTrack>> curvedTrackList;
	std::vector<std::shared_ptr<LinkedTrack>> linkedTrackList;
	std::vector<std::shared_ptr<ExitTrack>> exitTrackList;
	std::vector<std::shared_ptr<BufferTrack>> bufferTrackList;
	std::vector<std::shared_ptr<SignalTrack>> signalTrackList;
	std::vector<std::shared_ptr<BridgeUnderpassTrack>> bridgeUnderpassTrackList;
	std::vector<std::shared_ptr<SwitchTrack>> switchTrackList;
	std::vector<std::shared_ptr<CrossoverTrack>> crossoverTrackList;
	std::vector<std::shared_ptr<FlyoverTrack>> flyoverTrackList;
	std::vector<std::shared_ptr<NamedLocation>> namedLocationList;
	std::vector<std::shared_ptr<Concourse>> concourseList;
	std::vector<std::shared_ptr<Parapet>> parapetList;
	std::vector<std::shared_ptr<Text>> textList;

	std::vector<std::shared_ptr<Track>> trackList;

	/**
	 * @brief Adds a new StraightTrack to the vector.
	 * @param newStraightTrack The new StraightTrack to addd.
	 */
	void addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack);


public:

	//General map methods.
	/**
	 * @brief A default map constructor to create the map object.
	 */
	Map();

	/**
	 * @brief Gets the total number of track pieces that have been placed.
	 * @return An int that is the number of tracks placed.
	 */
	int getTotalTrack() const;

	/**
	 * @brief Sets the total number of track pieces that have beeen placed.
	 * @param newTrackTotal A new int that is the number of tracks placed.
	 */
	void setTotalTrack(int newTrackTotal);

	/**
	 * @brief Checks if an element exists at a location.
	 * @param locationX X coordinate to check.
	 * @param locationY Y coordinate to check.
	 * @return A bool that represents if an element exists there.
	 */
	bool checkElementExists(int locationX, int locationY);

	/**
	 * @brief Check if text exists at a location.
	 * @param locationX X coordinate to check.
	 * @param locationY Y coordinate to check.
	 * @return A bool that represents if text exists there.
	 */
	bool checkTextExists(int locationX, int locationY);

	//StraightTrack related methods.

	/**
	 * @brief Gets the list of StraightTrack pieces.
	 * @return A vector of shared pointers that point to StraightTracks.
	 */
	std::vector<std::shared_ptr<StraightTrack> > getStraightTrackList() const;

	/**
	 * @brief Sets the list of StraightTrack pieces.
	 * @param newStraightTrackList A new vector of shared pointers that point to StraightTracks.
	 */
	void setStraightTrackList(const std::vector<std::shared_ptr<StraightTrack> >& newStraightTrackList);

	/**
	 * @brief Creates the Straight track and adds it to the map if possible.
	 * @param straightType The straightType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddStraightTrack(StraightType straightType, int overallX, int overallY);

	/**
	 * @brief Gets the Straight Track at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return StraightTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<StraightTrack> getStraightTrackAt(int locationX,int locationY);
};

#endif // MAP_H
