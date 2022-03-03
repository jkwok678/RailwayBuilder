#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <QFont>
#include <memory>
#include <string>
#include <iostream>




/**
 * @brief The ParapetType enum
 *
 * There are 28 different parapets.
 */
enum class ParapetType
{
	PARAPET1, PARAPET2, PARAPET3, PARAPET4, PARAPET5, PARAPET6, PARAPET7, PARAPET8, PARAPET9,
	PARAPET10, PARAPET11, PARAPET12, PARAPET13, PARAPET14, PARAPET15, PARAPET16, PARAPET17, PARAPET18, PARAPET19, PARAPET20,
	PARAPET21, PARAPET22, PARAPET23, PARAPET24, PARAPET25, PARAPET26, PARAPET27, PARAPET28
};




/**
 * @brief The Element class.
 *
 * This class is the base class for all types of items that the user can place on screen.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Element
{
private:
	/**
	 * @brief Gets the X coordinate as a QString
	 * @return X coordinate as QString
	 */
	QString getLocationXToQString();

	/**
	 * @brief Gets the Y coordinate as a QString
	 * @return Y coordinate as QString
	 */
	QString getLocationYToQString();


protected:
	int locationX;
	int locationY;

public:
	/**
	 * @brief A default constructor for the Element class.
	 */
	Element();

	/**
	 * @brief A better element constructor.
	 * @param currentX The X coordinates of this element.
	 * @param currentY The Y coordinates of this element.
	 */
	Element(int currentX, int currentY);

	/**
	 * @brief A method that gets the X coordinate of the element.
	 * @return An int that represents the x coordinates.
	 */
	int getLocationX() const;

	/**
	 * @brief A method to set the X coordinate of the element.
	 * @param newLocationX The new X coordinate.
	 */
	void setLocationX(int newLocationX);

	/**
	 * @brief A method that gets the Y corrdinate of the element.
	 * @return An int that represents the Y coordinates.
	 */
	int getLocationY() const;

	/**
	 * @brief A method to set the Y coordinate of the element.
	 * @param newLocationY The new Y coordinate.
	 */
	void setLocationY(int newLocationY);

	/**
	 * @brief Gets the coordinates as a QString
	 * @return coordinates as a QString
	 */
	QString locationToQString();

	/**
	 * @brief A method to convert an element to a QString.
	 * @return QString representation of an element
	 */
	virtual QString toQString() = 0;

	/**
	 * @brief A method to convert an element to a QString for file saving.
	 * @return QString representation of element to be written to file.
	 */
	virtual QString toQStringForSave() = 0;

};




/**
 * @brief The Text class.
 *
 * This class extends the element class and is used for text that is placed on the canvas.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Text : public Element
{
private:
	int editableX;
	int editableY;
	int fontSize{12};
	QString readableText;
	QFont font;

protected:



public:
	/**
	 * @brief A constructor for the Text class
	 *
	 * This is an object for storing a bit of text that will appear on screen.
	 * It just contains the location and the text and the font.
	 * @param newLocationX The X coordinate where the text will appear on screen.
	 * @param newLocationY The Y coordinate where the text will appear on screen.
	 * @param newReadableText The actual text that will be displayed to the user.
	 * @param newFont The font that will be displayed to the user.
	 */
	Text(int newLocationX, int newLocationY, QString newReadableText, QFont newFont);

	/**
	 * @brief A method to get the X coordinate of the boundary point which the user can click to edit the text.
	 * @return An int that is the X cooridnate of the boundary point.
	 */
	int getEditableX() const;

	/**
	 * @brief A method to set the X coordinate of the boundary point which the user can click to edit the text.
	 * @param An int that is the new X coordinate of the boundary point.
	 */
	void setEditableX(int newEditableX);

	/**
	 * @brief A method to get the Y coordinate of the boundary point which the user can click to edit the text.
	 * @return An int that is the Y coordinate of the boundary point.
	 */
	int getEditableY() const;

	/**
	 * @brief A method to set the Y coordinate of the boundary point which the user can click to edit the text.
	 * @param An int that is the new Y coordinate of the boundary point.
	 */
	void setEditableY(int newEditableY);

	/**
	 * @brief A method to get the Font size.
	 * @return  An int that is the font size.
	 */
	int getFontSize() const;

	/**
	 * @brief A method to set the new font size.
	 * @param newFontSize The new font size for the text.
	 */
	void setFontSize(int newFontSize);

	/**
	 * @brief A method to get the actual text.
	 * @return  A QString that is the text.
	 */
	QString getReadableText() const;

	/**
	 * @brief A method to set the actual text.
	 * @param newReadableText The new text.
	 */
	void setReadableText(const QString& newReadableText);

	/**
	 * @brief A method to get the font object for this text.
	 * @return A QFont object.
	 */
	QFont getFont() const;

	/**
	 * @brief A method to set the font.
	 * @param newFont The new font.
	 */
	void setFont(const QFont newFont);

	/**
	 * @brief A method to convert a text to a String.
	 * @return QString representation of the text.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a Text to a QString for file saving.
	 * @return QString representation of Text to be written to file.
	 */
	QString toQStringForSave();

};




/**
 * @brief The NamedElement class.
 *
 * This class extends the element class and will be used by other classes that require a text object
 * to be linked to it.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class NamedElement : public Element
{
private:



protected:
	std::shared_ptr<Text> text {nullptr};

public:
	/**
	 * @brief A default constructor for NamedElement
	 */
	NamedElement();

	/**
	 * @brief A method to check if the element is named.
	 * @return A bool that says whether the element is named or not.
	 */
	bool getNamed() const;


	/**
	 * @brief A method to get the Text object that is linked to this namedElement.
	 * @return A Text object in a shared pointer.
	 */
	std::shared_ptr<Text> getText();

	/**
	 * @brief A method to set the Text that is linked to this namedElement
	 * @param newText The new text object you want the namedElement to have.
	 */
	void setText(std::shared_ptr<Text> &newText);

	/**
	 * @brief A method to convert a namedElement to a String.
	 * @return QString representation of the namedElement.
	 */
	QString toQString();

};




/**
 * @brief The NamedLocation class.
 *
 * This class extends the NamedElement class and acts like a concourse and needs to be named
 * with text. Text can be added using the methods declared in NamedElement. This block should be
 * blue.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class NamedLocation : public NamedElement
{
private:



protected:



public:
	/**
	 * @brief A constructor for the NamedLocation class.
	 * @param newLocationX X coordinate of the NamedLocation.
	 * @param newLocationY Y coordinate of the NamedLocation.
	 */
	NamedLocation(int newLocationX, int newLocationY);

	/**
	 * @brief A method to convert a namedLocation to a String.
	 * @return QString representation of the namedLocation.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a NamedLocation to a QString for file saving.
	 * @return QString representation of NamedLocation to be written to file.
	 */
	QString toQStringForSave();

};




/**
 * @brief The Concourse class.
 *
 * This class extends the NamedElement class and acts like a NamedLocation and needs to be named
 * with text. Text can be added using the methods declared in NamedElement. This block should be
 * red like the platforms.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Concourse : public NamedElement
{
private:



protected:



public:
	/**
	 * @brief A constructor for the Concourse class.
	 * @param newLocationX X coordinate of the Concourse.
	 * @param newLocationY Y coordinate of the Concourse.
	 */
	Concourse(int newLocationX, int newLocationY);

	/**
	 * @brief A method to convert a concourse to a String.
	 * @return QString representation of the concourse.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a Concourse to a QString for file saving.
	 * @return QString representation of Concourse to be written to file.
	 */
	QString toQStringForSave();
};




/**
 * @brief The Parapet class.
 *
 * This class extends the element class and is unlikely to have anything that extends from it.
 * It is just a structure that cannot be named.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Parapet : public Element
{
private:
	ParapetType parapetType;



protected:


public:
	/**
	 * @brief A constructor for the Parapet class.
	 * @param newParapetType The ParapetType.
	 * @param newLocationX X coordinate of the Parapet.
	 * @param newLocationY Y coordinate of the Parapet.
	 */
	Parapet(ParapetType newParapetType, int newLocationX, int newLocationY);

	/**
	 * @brief Gets the ParapetType enum.
	 * @return The ParapetType enum.
	 */
	ParapetType getParapetType() const;


	/**
	 * @brief Sets the ParapetType enum.
	 * @param newParapetType The new Parapet type enum.
	 */
	void setParapetType(const ParapetType &newParapetType);

	/**
	 * @brief Converts ParapetType to QString.
	 * @return QString that is the ParapetType.
	 */
	QString parapetTypeToQString();

	/**
	 * @brief A method to convert a Parapet to a String.
	 * @return QString representation of the Parapet.
	 */
	QString toQString();

	/**
	 * @brief A method to convert a Parapet to a QString for file saving.
	 * @return QString representation of a Parapet to be written to file.
	 */
	QString toQStringForSave();

};
#endif // ELEMENT_H
