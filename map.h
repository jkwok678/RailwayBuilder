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
	 * @param newDirectedTrack The new DirectedTrack to addd.
	 */
	void addDirectedTrack(std::shared_ptr<DirectedTrack> newDirectedTrack);

	/**
	 * @brief Adds a new CurvedTrack to the vector.
	 * @param newCurvedTrack The new CurvedTrack to addd.
	 */
	void addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack);

	/**
	 * @brief Adds a new LinkedTrack to the vector.
	 * @param newLinkedTrack The new LinkedTrack to addd.
	 */
	void addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack);

	/**
	 * @brief Adds a new ExitTrack to the vector.
	 * @param newExitTrack The new ExitTrack to addd.
	 */
	void addExitTrack(std::shared_ptr<ExitTrack> newExitTrack);

	/**
	 * @brief Adds a new BufferTrack to the vector.
	 * @param newBufferTrack The new BufferTrack to addd.
	 */
	void addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack);

	/**
	 * @brief Adds a new SignalTrack to the vector.
	 * @param newSignalTrack The new SignalTrack to addd.
	 */
	void addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack);

	/**
	 * @brief Adds a new BridgeUnderpassTrack to the vector.
	 * @param newBridgeUnderpassTrack The new BridgeUnderpassTrack to addd.
	 */
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
	 * @return A vector of shared pointers that point to DirectedTracks.
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

	/**
	 * @brief Gets the list of CurvedTrack pieces.
	 * @return A vector of shared pointers that point to CurvedTracks.
	 */
	std::vector<std::shared_ptr<CurvedTrack> > getCurvedTrackList() const;

	/**
	 * @brief Sets the list of CurvedTrack pieces.
	 * @param newCurvedTrackList A new vector of shared pointers that point to CurvedTracks.
	 */
	void setCurvedTrackList(const std::vector<std::shared_ptr<CurvedTrack> >& newCurvedTrackList);

	/**
	 * @brief Creates the CurvedTrack and adds it to the map if possible.
	 * @param curvedType The CurvedType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddCurvedTrack(CurvedType curvedType, int overallX, int overallY);

	/**
	 * @brief Gets the CurvedTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return CurvedTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<CurvedTrack> getCurvedTrackAt(int locationX,int locationY);

	//LinkedTrack related methods

	/**
	 * @brief Gets the list of LinkedTrack pieces.
	 * @return A vector of shared pointers that point to LinkedTracks.
	 */
	std::vector<std::shared_ptr<LinkedTrack> > getLinkedTrackList() const;

	/**
	 * @brief Sets the list of LinkedTrack pieces.
	 * @param newLinkedTrackList A new vector of shared pointers that point to LinkedTracks.
	 */
	void setLinkedTrackList(const std::vector<std::shared_ptr<LinkedTrack> >& newLinkedTrackList);

	/**
	 * @brief Creates the LinkedTrack and adds it to the map if possible.
	 * @param linkedType The LinkedType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddLinkedTrack(LinkedType linkedType, int overallX, int overallY);

	/**
	 * @brief Gets the LinkedTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return LinkedTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<LinkedTrack> getLinkedTrackAt(int locationX,int locationY);

	//bool haslinkTrackAt(int locationX, int locationY);

	//ExitTrack related methods

	/**
	 * @brief Gets the list of ExitTrack pieces.
	 * @return A vector of shared pointers that point to ExitTracks.
	 */
	std::vector<std::shared_ptr<ExitTrack> > getExitTrackList() const;

	/**
	 * @brief Sets the list of ExitTrack pieces.
	 * @param newExitTrackList A new vector of shared pointers that point to ExitTracks.
	 */
	void setExitTrackList(const std::vector<std::shared_ptr<ExitTrack> >& newExitTrackList);

	/**
	 * @brief Creates the ExitTrack and adds it to the map if possible.
	 * @param exitType The ExitType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddExitTrack(ExitType exitType, int overallX, int overallY);

	/**
	 * @brief Gets the ExitTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return ExitTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<ExitTrack> getExitTrackAt(int locationX,int locationY);

	//BufferTrack related methods

	/**
	 * @brief Gets the list of BufferTrack pieces.
	 * @return A vector of shared pointers that point to BufferTracks.
	 */
	std::vector<std::shared_ptr<BufferTrack> > getBufferTrackList() const;

	/**
	 * @brief Sets the list of BufferTrack pieces.
	 * @param newBufferTrackList A new vector of shared pointers that point to BufferTracks.
	 */
	void setBufferTrackList(const std::vector<std::shared_ptr<BufferTrack> >& newBufferTrackList);

	/**
	 * @brief Creates the BufferTrack and adds it to the map if possible.
	 * @param bufferType The BufferType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddBufferTrack(BufferType bufferType, int overallX, int overallY);

	/**
	 * @brief Gets the BufferTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return BufferTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<BufferTrack> getBufferTrackAt(int locationX,int locationY);

	//SignalTrack related methods

	/**
	 * @brief Gets the list of SignalTrack pieces.
	 * @return A vector of shared pointers that point to SignalTracks.
	 */
	std::vector<std::shared_ptr<SignalTrack> > getSignalTrackList() const;

	/**
	 * @brief Sets the list of SignalTrack pieces.
	 * @param newSignalTrackList A new vector of shared pointers that point to SignalTracks.
	 */
	void setSignalTrackList(const std::vector<std::shared_ptr<SignalTrack> >& newSignalTrackList);

	/**
	 * @brief Creates the SignalTrack and adds it to the map if possible.
	 * @param signalType The SignalType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddSignalTrack(SignalType signalType,int aspect, int overallX, int overallY);

	/**
	 * @brief Gets the SignalTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return SignalTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<SignalTrack> getSignalTrackAt(int locationX,int locationY);

	//BridgeUnderpassTrackList

	/**
	 * @brief Gets the list of BridgeUnderpassTrack pieces.
	 * @return A vector of shared pointers that point to BridgeUnderpassTracks.
	 */
	std::vector<std::shared_ptr<BridgeUnderpassTrack>> getBridgeUnderpassTrackList() const;

	/**
	 * @brief Sets the list of BridgeUnderpassTrack pieces.
	 * @param newBridgeUnderpassTrackList A new vector of shared pointers that point to BridgeUnderpassTracks.
	 */
	void setBridgeUnderpassTrackList(const std::vector<std::shared_ptr<BridgeUnderpassTrack> >& newBridgeUnderpassTrackList);

	/**
	 * @brief Creates the BridgeUnderpassTrack and adds it to the map if possible.
	 * @param bridgeUnderpassTrack The BridgeUnderpassType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddBridgeUnderpassTrack(BridgeUnderpassType bridgeUnderpassTrack, int overallX, int overallY);

	/**
	 * @brief Gets the BridgeUnderpassTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return BridgeUnderpassTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<BridgeUnderpassTrack> getBridgeUnderpassTrack(int locationX,int locationY);
};

#endif // MAP_H
