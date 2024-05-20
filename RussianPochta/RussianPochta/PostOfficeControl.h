/**
 * @file PostOfficeControl.h
 * @brief Интерфейс управления почтовыми отделениями и посылками.
 *
 * Файл содержит объявления функций для создания, редактирования, удаления почтовых отделений,
 * а также для управления посылками, включая отправку, поиск и доставку.
 *
 * @version 1.0
 * @date 17.05.2024
 *
 * @note Этот интерфейс нужен для работы с почтовыми отделениями и посылками.
 *
 * @see PostOffice
 * @see Parcel
 *
 */

#pragma once

#include <string>
#include <vector>
#include <cmath>

#include "PostOffice.h"
#include "Parcel.h"

using namespace std;

/**
 * @namespace PostOfficeControl
 * @brief Пространство имен для функций управления почтовыми отделениями и посылками.
 *
 * Пространство имен PostOfficeControl содержит функции для создания, удаления, редактирования почтовых отделений,
 * а также для отправки, поиска и доставки посылок.
 */
namespace PostOfficeControl {

    /**
     * @brief Создает новые почтовые отделения.
     *
     * Создает и сохраняет заданное количество новых почтовых отделений.
     *
     * @param n Количество отделений почты для создания.
     */
    void createPostOffice(const int n);

    /**
     * @brief Удаляет существующее почтовое отделение.
     *
     * Удаляет почтовое отделение, выбранное пользователем.
     */
    void removePostOffice();

    /**
     * @brief Редактирует существующее почтовое отделение.
     *
     * Позволяет пользователю изменить информацию о выбранном почтовом отделении.
     */
    void editPostOffice();

    /**
     * @brief Сохраняет данные о почтовых отделениях в файл.
     *
     * Сохраняет текущие данные о почтовых отделениях в файл для последующего использования.
     *
     * @param arr Вектор почтовых отделений для сохранения.
     * @param n Количество почтовых отделений для сохранения.
     */
    void savePostOffice(std::vector<PostOffice> arr, const int& n);

    /**
     * @brief Читает данные о почтовых отделениях из файла.
     *
     * Загружает данные о почтовых отделениях из файла.
     *
     * @return std::vector<PostOffice> Вектор почтовых отделений.
     */
    std::vector<PostOffice> readPostOffice();

    /**
     * @brief Возвращает количество почтовых отделений.
     *
     * Читает файл и возвращает количество почтовых отделений, сохраненных в нем.
     *
     * @return int Количество почтовых отделений.
     */
    int getCountPostOffice();

    void sendParcel();

    void findParcel();

    int getCountParcel();

    void deliveryParcel();

    void checkStatusParcels();

    std::vector<Parcel> readParcel();

    void saveParcel(std::vector<Parcel> arr, const int& n);

    time_t timeLocation(PostOffice& sender, PostOffice& receiver);

    void rewindTime();

    void progressTime();

    void print();

    int inputInteger();
}