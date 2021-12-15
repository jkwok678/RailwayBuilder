#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QObject>
#include "element.h"
#include "track.h"
#include "message.h"

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

	int imageSize{16};
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

	std::shared_ptr<LinkedTrack> linkedTrack1{nullptr};
	std::shared_ptr<LinkedTrack> linkedTrack2{nullptr};

	std::shared_ptr<Text> textToMove{nullptr};

	//General methods.



	//Adding element methods.

	/**
	 * @brief Adds a new StraightTrack to the vector.
	 * @param newStraightTrack The new StraightTrack to add.
	 */
	void addStraightTrack(std::shared_ptr<StraightTrack> newStraightTrack);

	/**
	 * @brief Adds a new DirectedTrack to the vector.
	 * @param newDirectedTrack The new DirectedTrack to add.
	 */
	void addDirectedTrack(std::shared_ptr<DirectedTrack> newDirectedTrack);

	/**
	 * @brief Adds a new CurvedTrack to the vector.
	 * @param newCurvedTrack The new CurvedTrack to add.
	 */
	void addCurvedTrack(std::shared_ptr<CurvedTrack> newCurvedTrack);

	/**
	 * @brief Adds a new LinkedTrack to the vector.
	 * @param newLinkedTrack The new LinkedTrack to add.
	 */
	void addLinkedTrack(std::shared_ptr<LinkedTrack> newLinkedTrack);

	/**
	 * @brief Adds a new ExitTrack to the vector.
	 * @param newExitTrack The new ExitTrack to add.
	 */
	void addExitTrack(std::shared_ptr<ExitTrack> newExitTrack);

	/**
	 * @brief Adds a new BufferTrack to the vector.
	 * @param newBufferTrack The new BufferTrack to add.
	 */
	void addBufferTrack(std::shared_ptr<BufferTrack> newBufferTrack);

	/**
	 * @brief Adds a new SignalTrack to the vector.
	 * @param newSignalTrack The new SignalTrack to add.
	 */
	void addSignalTrack(std::shared_ptr<SignalTrack> newSignalTrack);

	/**
	 * @brief Adds a new BridgeUnderpassTrack to the vector.
	 * @param newBridgeUnderpassTrack The new BridgeUnderpassTrack to add.
	 */
	void addBridgeUnderpassTrack(std::shared_ptr<BridgeUnderpassTrack> newBridgeUnderpassTrack);

	/**
	 * @brief Adds a new SwitchTrack to the vector.
	 * @param newSwitchTrack The new SwitchTrack to add.
	 */
	void addSwitchTrack(std::shared_ptr<SwitchTrack> newSwitchTrack);

	/**
	 * @brief Adds a new CrossoverTrack to the vector.
	 * @param newCrossoverTrack The new CrossoverTrack to add.
	 */
	void addCrossoverTrack(std::shared_ptr<CrossoverTrack> newCrossoverTrack);

	/**
	 * @brief Adds a new FlyoverTrack to the vector.
	 * @param newFlyoverTrack The new FlyoverTrack to add.
	 */
	void addFlyoverTrack(std::shared_ptr<FlyoverTrack> newFlyoverTrack);

	/**
	 * @brief Adds a new NamedLocation to the vector.
	 * @param newNamedLocation The new NamedLocation to add.
	 */
	void addNamedLocation(std::shared_ptr<NamedLocation> newNamedLocation);

	/**
	 * @brief Adds a new Concourse to the vector.
	 * @param newConcourse The new Concourse to add.
	 */
	void addConcourse(std::shared_ptr<Concourse> newConcourse);

	/**
	 * @brief Adds a new Parapet to the vector.
	 * @param newParapet The new Parapet to add.
	 */
	void addParapet(std::shared_ptr<Parapet> newParapet);

	/**
	 * @brief Adds a new Text to the vector.
	 * @param newText The new Text to add.
	 */
	void addText(std::shared_ptr<Text> newText);


	//Remove element methods

	/**
	 * @brief Removes a StraightTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Straight Track.
	 * @param yLocation The Y coordinate of the Straight Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeStraightTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a DirectedTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Directed Track.
	 * @param yLocation The Y coordinate of the Directed Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeDirectedTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a CurvedTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Curved Track.
	 * @param yLocation The Y coordinate of the Curved Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeCurvedTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a LinkedTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Linked Track.
	 * @param yLocation The Y coordinate of the Linked Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeLinkedTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a ExitTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Exit Track.
	 * @param yLocation The Y coordinate of the Exit Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeExitTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a BufferTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Buffer Track.
	 * @param yLocation The Y coordinate of the Buffer Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeBufferTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a SignalTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Signal Track.
	 * @param yLocation The Y coordinate of the Signal Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeSignalTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a BridgeUnderpassTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the BridgeUnderpass Track.
	 * @param yLocation The Y coordinate of the BridgeUnderpass Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeBridgeUnderpassTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a SwitchTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Switch Track.
	 * @param yLocation The Y coordinate of the Switch Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeSwitchTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a CrossoverTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Crossover Track.
	 * @param yLocation The Y coordinate of the Crossover Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeCrossoverTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a FlyoverTrack from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Flyover Track.
	 * @param yLocation The Y coordinate of the Flyover Track.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeFlyoverTrack(int xLocation, int yLocation);

	/**
	 * @brief Removes a NamedLocation from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the NamedLocation.
	 * @param yLocation The Y coordinate of the NamedLocation.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeNamedLocation(int xLocation, int yLocation);

	/**
	 * @brief Removes a Concourse from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Concourse.
	 * @param yLocation The Y coordinate of the Concourse.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeConcourse(int xLocation, int yLocation);

	/**
	 * @brief Removes a Parapet from those coordinates if it exists there.
	 * @param xLocation The X coordinate of the Parapet.
	 * @param yLocation The Y coordinate of the Parapet.
	 * @return true if a track was deleted, false if nothing was deleted
	 */
	bool removeParapet(int xLocation, int yLocation);

	//Linked Track private methods

	/**
	 * @brief A method that links the 2 chosen LinkedTracks.
	 */
	void connectLinkedTrack();

	/**
	 * @brief A method that disconnects the 2 chosen LinkedTracks.
	 */
	void disconnectLinkedTrack(std::shared_ptr<LinkedTrack> linkTrack1, std::shared_ptr<LinkedTrack> linkedTrack2);

	/**
	 * @brief A method to reset the connectLinkedTrack mechanics.
	 */
	void resetConnectLinkedTrack();

	//General methods

	/**
	 * @brief Gets the top left track.
	 * @return the top left track.
	 */
	std::shared_ptr<Track> findTopLeftTrack();

public:

	//General map methods.
	/**
	 * @brief A default map constructor to create the map object.
	 */
	Map();

	/**
	 * @brief Gets the image size of the elements.
	 * @return an int that is the image size.
	 */
	int getImageSize() const;

	/**
	 * @brief Sets the image size of the elements.
	 * @param newImageSize an int that is the new image size.
	 */
	void setImageSize(int newImageSize);

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

	/**
	 * @brief Gets the straightTrackList as a QString for file saving.
	 * @return A QString of StraightTracks for file saving
	 */
	QString straightTrackListToQStringForSaving();

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

		//Connecting Linked tracks methods

	/**
	 * @brief A method to get the first LinkedTrack.
	 * @return The first LinkedTrack chosen.
	 */
	std::shared_ptr<LinkedTrack> getLinkedTrack1() const;

	/**
	 * @brief A method to set the first chosen LinkedTrack.
	 * @param newLinkedTrack1 The first chosen LinkedTrack.
	 */
	void setLinkedTrack1(const std::shared_ptr<LinkedTrack> &newLinkedTrack1);

	/**
	 * @brief A method to get the second LinkedTrack.
	 * @return The second LinkedTrack chosen.
	 */
	std::shared_ptr<LinkedTrack> getLinkedTrack2() const;

	/**
	 * @brief A method to set the second chosen LinkedTrack.
	 * @param newLinkedTrack2 The second chosen LinkedTrack.
	 */
	void setLinkedTrack2(const std::shared_ptr<LinkedTrack> &newLinkedTrack2);


	/**
	 * @brief Checks if there is a linked track at that location
	 * @param locationX X coordinate.
	 * @param locationY Y coordinate.
	 * @return A bool, true if there is a linked track there false if not.
	 */
	bool hasLinkedTrackAt(int locationX, int locationY);

	/**
	 * @brief Connects the last two chosen linked tracks.
	 * @param locationX X coordinate of a linked track.
	 * @param locationY Y coordinate of a linked track.
	 */
	void connectTwoLinkedTracks(int locationX, int locationY);

	/**
	 * @brief Checks if all LinkedTracks are connected.
	 * @return true if all linked tracks are connected, otherwise false.
	 */
	bool checkAllLinkTrackLinked();



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

	//BridgeUnderpassTrack related methods

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
	 * @param bridgeUnderpassType The BridgeUnderpassType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddBridgeUnderpassTrack(BridgeUnderpassType bridgeUnderpassType, int overallX, int overallY);

	/**
	 * @brief Gets the BridgeUnderpassTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return BridgeUnderpassTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<BridgeUnderpassTrack> getBridgeUnderpassTrack(int locationX,int locationY);

	//SwitchTrack related methods

	/**
	 * @brief Gets the list of SwitchTrack pieces.
	 * @return A vector of shared pointers that point to SwitchTracks.
	 */
	std::vector<std::shared_ptr<SwitchTrack> > getSwitchTrackList() const;

	/**
	 * @brief Sets the list of SwitchTrack pieces.
	 * @param newSwitchTrackList A new vector of shared pointers that point to SwitchTracks.
	 */
	void setSwitchTrackList(const std::vector<std::shared_ptr<SwitchTrack> >& newSwitchTrackList);

	/**
	 * @brief Creates the SwitchTrack and adds it to the map if possible.
	 * @param switchType The SwitchType of the track.
	 * @param overallX X coordinate of the track.
	 * @param overallY Y coordinate of the track.
	 */
	void createAddSwitchTrack(SwitchType switchType, int overallX, int overallY);

	/**
	 * @brief Gets the SwitchTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return SwitchTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<SwitchTrack> getSwitchTrackAt(int locationX,int locationY);

	//CrossoverTrack related methods

	/**
	 * @brief Gets the list of CrossoverTrack pieces.
	 * @return A vector of shared pointers that point to CrossoverTracks.
	 */
	std::vector<std::shared_ptr<CrossoverTrack> > getCrossoverTrackList() const;

	/**
	 * @brief Sets the list of CrossoverTrack pieces.
	 * @param newCrossoverTrackList A new vector of shared pointers that point to CrossoverTracks.
	 */
	void setCrossoverTrackList(const std::vector<std::shared_ptr<CrossoverTrack> >& newCrossoverTrackList);

	/**
	 * @brief Creates the CrossoverTrack and adds it to the map if possible.
	 * @param crossoverType The CrossoverType of the track.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	void createAddCrossoverTrack(CrossoverType crossoverType, int overallX, int overallY);

	/**
	 * @brief Gets the CrossoverTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return CrossoverTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<CrossoverTrack> getCrossoverTrackAt(int locationX,int locationY);

	//FlyoverTrack related methods

	/**
	 * @brief Gets the list of FlyoverTrack pieces.
	 * @return A vector of shared pointers that point to FlyoverTracks.
	 */
	std::vector<std::shared_ptr<FlyoverTrack> > getFlyoverTrackList() const;

	/**
	 * @brief Sets the list of FlyoverTrack pieces.
	 * @param newFlyoverTrackList A new vector of shared pointers that point to FlyoverTracks.
	 */
	void setFlyoverTrackList(const std::vector<std::shared_ptr<FlyoverTrack> >& newFlyoverTrackList);

	/**
	 * @brief Creates the FlyoverTrack and adds it to the map if possible.
	 * @param flyoverType The FlyoverType of the track.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	void createAddFlyoverTrack(FlyoverType flyoverType, int overallX, int overallY);

	/**
	 * @brief Gets the FlyoverTrack at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return FlyoverTrack at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<FlyoverTrack> getFlyoverTrackAt(int locationX,int locationY);

	//NamedLocation related methods.

	/**
	 * @brief Gets the list of NamedLocations.
	 * @return A vector of shared pointers that points to NamedLocations.
	 */
	std::vector<std::shared_ptr<NamedLocation> > getNamedLocationList() const;

	/**
	 * @brief Sets the list of NamedLocations.
	 * @param newNamedLocationList A new vector of shared pointers that point to NamedLocations.
	 */
	void setNamedLocationList(const std::vector<std::shared_ptr<NamedLocation> >& newNamedLocationList);

	/**
	 * @brief Creates the NamedLocation and adds it to the map if possible.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	void createAddNamedLocation(int overallX, int overallY);

	/**
	 * @brief Gets the NamedLocation at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return NamedLocation at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<NamedLocation> getNamedLocationAt(int locationX,int locationY);

	//Concourse related methods.

	/**
	 * @brief Gets the list of Concourses.
	 * @return A vector of shared pointers that points to Concourses.
	 */
	std::vector<std::shared_ptr<Concourse> > getConcourseList() const;

	/**
	 * @brief Sets the list of Concourses.
	 * @param newConourseList A new vector of shared pointers that point to Concourses.
	 */
	void setConcourseList(const std::vector<std::shared_ptr<Concourse> >& newConcourseList);

	/**
	 * @brief Creates the Concourse and adds it to the map if possible.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	void createAddConcourse(int overallX, int overallY);

	/**
	 * @brief Gets the Concourse at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return Concourse at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<Concourse> getConcourseAt(int locationX,int locationY);

	//Parapet related methods.

	/**
	 * @brief Gets the list of Parapets.
	 * @return A vector of shared pointers that points to Parapets.
	 */
	std::vector<std::shared_ptr<Parapet> > getParapetList() const;

	/**
	 * @brief Sets the list of Parapets.
	 * @param newParapetList A new vector of shared pointers that point to Parapets.
	 */
	void setParapetList(const std::vector<std::shared_ptr<Parapet> >& newParapetList);

	/**
	 * @brief Creates the Parapets and adds it to the map if possible.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	void createAddParapet(ParapetType parapetType, int overallX, int overallY);

	/**
	 * @brief Gets the Parapet at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return Parapet at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<Parapet> getParapetAt(int locationX,int locationY);

	//Text related methods.

	/**
	 * @brief Gets the list of Text.
	 * @return A vector of shared pointers that points to Texts.
	 */
	std::vector<std::shared_ptr<Text> > getTextList() const;

	/**
	 * @brief Sets the list of Texts.
	 * @param newTextList A new vector of shared pointers that point to Texts.
	 */
	void setTextList(const std::vector<std::shared_ptr<Text> >& newTextList);

	/**
	 * @brief Creates the Text and adds it to the map if possible.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	std::shared_ptr<Text> createAddText(int overallX, int overallY, QString readableBit, QFont currentFont);

	/**
	 * @brief Creates the Text, adds it to the map if possible then link it with it's neighbours.
	 * @param overallX X coordinate to look at.
	 * @param overallY Y coordinate to look at.
	 */
	void createAddLinkText(int overallX, int overallY, QString readableBit, bool ok, QFont currentFont);

	/**
	 * @brief Gets the Parapet at given coordinates if one exists there.
	 * @param locationX X coordinate to look at.
	 * @param locationY Y coordinate to look at.
	 * @return Parapet at (X,Y) if there is one, otherwise return a nullptr.
	 */
	std::shared_ptr<Text> getTextAt(int locationX,int locationY);

	/**
	 * @brief Check if text exists in an area.
	 * @param locationX X coordinate to check.
	 * @param locationY Y coordinate to check.
	 * @return A bool that represents if text exists there.
	 */
	bool checkTextExists(int locationX, int locationY);

	/**
	 * @brief Delete text if it exists.
	 * @param textToDelete The Text to delete.
	 * @return true if deleted  otherwise false.
	 */
	bool deleteText (std::shared_ptr<Text> textToDelete);

	/**
	 * @brief Delete the text from all elements
	 * @param textToDelete The text to delte from all elements.
	 */
	void deleteTextFromAllElements(std::shared_ptr<Text> textToDelete);

	/**
	 * @brief Get the text that needs to be moved.
	 * @return The text to move.
	 */
	std::shared_ptr<Text> getTextToMove() const;

	/**
	 * @brief Set the text that needs to be moved with coordinates.
	 * @param exactX X Coordinate.
	 * @param exactY Y Coordinate.
	 * @return true if set, false if no.
	 */
	bool setTextToMove(int exactX, int exactY);

	/**
	 * @brief Set the text that needs to be moved.
	 * @param newTextToMove The new text to be moved.
	 */
	void setTextToMove(const std::shared_ptr<Text> &newTextToMove);

	/**
	 * @brief Moves text from old coordinates to the new coordinates.
	 * @param exactX X Coordinate.
	 * @param exactY Y Coordinate.
	 */
	void moveText(int exactX, int exactY);

	/**
	 * @brief Changes or deletes a text depending on input from the user.
	 * @param readableBit
	 * @param text
	 */
	void changeDeleteText(QString readableBit, bool ok, std::shared_ptr<Text> text);

	/**
	 * @brief Links text to items that are neighbours.
	 *
	 * X and Y coordinates is the item the place to look for neighbours.
	 *
	 * @param locationX X Coordinate.
	 * @param LocationY Y Coordinate.
	 * @param linkedText THe text to link to.
	 */
	void linkLocalText(int locationX, int locationY, std::shared_ptr<Text> linkedText);


	//Platform related methods

	/**
	 * @brief Adds a platform to a track, if its possible.
	 * @param side The side of the platform relative to the track.
	 * @param locationX X coordinate of the track.
	 * @param locationY Y coordinate of the track.
	 */
	void addPlatform(Platform side, int locationX, int locationY);

	/**
	 * @brief Adds a level crossing if it's possible.
	 * @param locationX X coordinate of the track.
	 * @param locationY Y coordinate of the track.
	 */
	void addLevelCrossing( int locationX, int locationY);

	//Deleting methods

	/**
	 * @brief Deletes an element from storage.
	 * @param locationX X coordinate of the element to delete.
	 * @param locationY Y coordinate of the element to delete.
	 * @return true if something was deleted at those coordinates, otherwise false.
	 */
	bool deleteElement(int locationX, int locationY);

	//General methods

	/**
	 * @brief Gets the element at the coordinates.
	 * @param locationX X coordinate of the element.
	 * @param locationY Y coordinate of the element.
	 * @return an element, otherwise nullptr.
	 */
	std::shared_ptr<Element> getElementAt( int locationX, int locationY);


	/**
	 * @brief Gets the namedElement at the coordinates.
	 * @param locationX X coordinate of the element.
	 * @param locationY Y coordinate of the element.
	 * @return a element, otherwise nullptr.
	 */
	std::shared_ptr<NamedElement> getNamedElementAt( int locationX, int locationY);

	/**
	 * @brief Gets the track at the coordinates.
	 * @param locationX X coordinate of the track.
	 * @param locationY Y coordinate of the track.
	 * @return a track, otherwise nullptr.
	 */
	std::shared_ptr<Track> getTrackAt( int locationX, int locationY);

	/**
	 * @brief Gets the Straight track at the coordinates.
	 * @param locationX X coordinate of the track.
	 * @param locationY Y coordinate of the track.
	 * @return a striaght track, otherwise nullptr.
	 */
	std::shared_ptr<StraightTrack> getTrackHasPlatformAt( int locationX, int locationY);


	/**
	 * @brief Gets the trackList.
	 * @return A list of every track.
	 */
	std::vector<std::shared_ptr<Track> > getTrackList() const;

	/**
	 * @brief Sets the trackList.
	 * @param value
	 */
	void setTrackList(const std::vector<std::shared_ptr<Track> > &newTrackList);

	/**
	 * @brief Makes the trackList.
	 */
	void makeTrackList();

	/**
	 * @brief Checks if all tracks are connected.
	 * @return true if they are, otherwise false.
	 */
	bool checkAllTracksConnected();

};

#endif // MAP_H
