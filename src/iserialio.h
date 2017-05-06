#ifndef ABSTRACTSERIALIO_H
#define ABSTRACTSERIALIO_H

#include <QObject>

#define COMMAND_CLEAR_SCREEN (0xFFC1)

/**
 * @brief Интерфейс для передачи и приема данных по последовательному порту без доступа к его настройкам
 */
class ISerialIO : public QObject
{
    Q_OBJECT

public:
    explicit ISerialIO(QObject *parent) : QObject(parent) {}
    virtual ~ISerialIO() {}

    /**
     * @brief Передать произвольный набор данных
     * @param data Данные
     */
    virtual void writeAsync(const QByteArray &data) =0;
    /**
     * @brief Передать байт данных
     * @param byte Байт
     */
    virtual void writeAsyncByte(quint8 byte) =0;
    /**
     * @brief Передать два байта данных
     * @param bytes 2 Байта
     */
    virtual void writeAsync2Bytes(quint16 bytes) =0;

signals:
    /**
     * @brief В буффере приема появились данные
     * @param data Принятые данные
     */
    void dataRecieved(const QByteArray &data);
    /**
     * @brief Данные переданы
     * @param bytes Переданные данные
     */
    void dataWritten(qint64 bytes);

};

#endif // ABSTRACTSERIALIO_H
