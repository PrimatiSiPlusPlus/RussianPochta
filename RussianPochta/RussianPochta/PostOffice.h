/**
 * @file PostOffice.h
 * @brief Описание класса почтового отделения и его методов.
 *
 * Файл содержит описание класса PostOffice, представляющего почтовое отделение, и его методов для
 * управления информацией о почтовом отделении.
 *
 * @version 1.0
 * @date 17.05.2024
 *
 * @note Этот класс используется для представления и управления почтовыми отделениями.
 *
 */

#pragma once

#include <string>
#include <iostream>

 /**
  * @class PostOffice
  * @brief Класс, представляющий почтовое отделение.
  *
  * Класс содержит информацию о почтовом отделении, включая название, координаты и индекс.
  */
class PostOffice {
private:
    int index;                  ///< Индекс почтового отделения.
    int coordinateX;            ///< Координата X местоположения почтового отделения.
    int coordinateY;            ///< Координата Y местоположения почтового отделения.
    std::string name;           ///< Название почтового отделения.

public:
    /**
     * @brief Возвращает координату X местоположения почтового отделения.
     *
     * @return int Координата X.
     */
    int getCoordinateX();

    /**
     * @brief Возвращает индекс почтового отделения.
     *
     * @return int Индекс.
     */
    int getIndex();

    /**
     * @brief Возвращает координату Y местоположения почтового отделения.
     *
     * @return int Координата Y.
     */
    int getCoordinateY();

    /**
     * @brief Возвращает название почтового отделения.
     *
     * @return std::string Название.
     */
    std::string getNameOffice();

    /**
     * @brief Устанавливает индекс почтового отделения.
     *
     * @param Index Новый индекс.
     */
    void setIndex(int Index);

    /**
     * @brief Устанавливает координату X местоположения почтового отделения.
     *
     * @param X Новая координата X.
     */
    void setCoordinateX(int X);

    /**
     * @brief Устанавливает координату Y местоположения почтового отделения.
     *
     * @param Y Новая координата Y.
     */
    void setCoordinateY(int Y);

    /**
     * @brief Устанавливает название почтового отделения.
     *
     * @param Name Новое название.
     */
    void setNameOffice(std::string Name);

    /**
     * @brief Перегрузка оператора ввода.
     *
     * Запрашивает у пользователя информацию о почтовом отделении и устанавливает соответствующие поля.
     *
     * @param in Входной поток.
     * @param office Почтовое отделение для ввода данных.
     * @return std::istream& Входной поток.
     */
    friend std::istream& operator>>(std::istream& in, PostOffice& office);

    /**
     * @brief Перегрузка оператора вывода.
     *
     * Выводит информацию о почтовом отделении.
     *
     * @param out Выходной поток.
     * @param office Почтовое отделение для вывода данных.
     * @return std::ostream& Выходной поток.
     */
    friend std::ostream& operator<<(std::ostream& out, const PostOffice& office);
};