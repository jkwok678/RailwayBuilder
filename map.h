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
	std::vector<std::shared_ptr<DirectedTrack>> directedTrackList;
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
	 * @brief Shows the user an error message saying they cannot place an element on top of an existing element.
	 */
	void showElementAlreadyThereError();

	/**
	 * @brief Adds a new StraightTrack to the vector.
	 * @param newStraightTrack The new StraightTrack to addd.
	 */
	void addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack);

	/**
	 * @brief Adds a new DirectedTrack to the vector.
	 * @param newStraightTrack The new StraightTrack to addd.
	 */
	void addDirectedTrack(std::shared_ptr<DirectedTrack> newDirectedTrack);

	void addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack);

	void addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack);

	void addExitTrack(std::shared_ptr<ExitTrack> newExitTrack);

	void addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack);

	void addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack);

	void addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack);

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
	 * @brief Creates the StraightTrack and adds it to the map if possible.
	 * @param straightType The straightType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddStraightTrack(StraightType straightType, int overallX, int overallY);

	/**
	 * @brief Gets the StraightTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return StraightTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<StraightTrack> getStraightTrackAt(int locationX,int locationY);

	//DirectedTrack related methods.

	/**
	 * @brief Gets the list of DirectedTrack pieces.
	 * @return A vector of shared pointers that point to StraightTracks.
	 */
	std::vector<std::shared_ptr<DirectedTrack> > getDirectedTrackList() const;

	/**
	 * @brief Sets the list of DirectedTrack pieces.
	 * @param newDirectedTrackList A new vector of shared pointers that point to DirectedTracks.
	 */
	void setDirectedTrackList(const std::vector<std::shared_ptr<DirectedTrack> >& newDirectedTrackList);

	/**
	 * @brief Creates the DirectedTrack and adds it to the map if possible.
	 * @param directedType The DirectedType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddDirectedTrack(DirectedType directedType, int overallX, int overallY);

	/**
	 * @brief Gets the DirectedTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return DirectedTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<DirectedTrack> getDirectedTrackAt(int locationX,int locationY);

	//CurvedTrack related methods

	std::vector<std::shared_ptr<CurvedTrack> > getCurvedTrackList() const;
	void setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> >& newCurvedTrackList);

	std::shared_ptr<CurvedTrack> getCurvedTrackAt(int locationX,int locationY);

	std::vector<std::shared_ptr<LinkedTrack> > getLinkedTrackList() const;
	void setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> >& newLinkedTrackList);

	std::shared_ptr<LinkedTrack> getLinkedTrackAt(int locationX,int locationY);
	bool haslinkTrackAt(int locationX, int locationY);

	std::vector<std::shared_ptr<ExitTrack> > getExitTrackList() const;
	void setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> >& newExitTrackList);

	std::shared_ptr<ExitTrack> getExitTrackAt(int locationX,int locationY);

	std::vector<std::shared_ptr<BufferTrack> > getBufferTrackList() const;
	void setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> >& newBufferTrackList);

	std::shared_ptr<BufferTrack> getBufferTrackAt(int locationX,int locationY);

	std::vector<std::shared_ptr<SignalTrack> > getSignalTrackList() const;
	void setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> >& newSignalTrackList);

	std::shared_ptr<SignalTrack> getSignalTrackAt(int locationX,int locationY);

	std::vector<std::shared_ptr<BridgeUnderpassTrack>> getBridgeUnderpassTrackList() const;
	void setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> >& newBridgeUnderpassTrackList);

	std::shared_ptr<BridgeUnderpassTrack> getBridgeUnderpassTrack(int locationX,int locationY);
};

#endif // MAP_H
