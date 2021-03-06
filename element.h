#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>
#include <QFont>
#include <memory>
#include <string>
#include <iostream>

/**
 * @brief The Element class
 *
 * This class is the base class for all types of items that the user can place on screen.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Element
{
private:

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
};



/**
 * @brief The Text class
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
	int fontSize{ 12 };
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
};



/**
 * @brief The NamedElement class
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
	bool named { false };
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
	 * @brief A method to set whether the element is named or not.
	 * @param newNamed Whether the element is named or not.
	 */
	void setNamed(bool newNamed);
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
};

#endif // ELEMENT_H
