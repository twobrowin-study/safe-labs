#ifndef USER_H
#define USER_H

#include <QDate>
#include <QString>

struct User {
    QString user_name;
    QString password;
    QString sur_name;
    QString name;
    QString sec_name;
    QDate birth_day;
    QString birth_place;
    QString phone_number;

    enum PasswordMalfunctionsTypes
    {
        PASSWORD_OK,
        PASSWORD_BAD_LENGTH,
        PASSWORD_BAD_FORMAT,
        PASSWORD_EQ_BIRTH_DATE,
    };

    PasswordMalfunctionsTypes checkPassword(QString password)
    {
        if (password.length() != 8)
        {
            return PASSWORD_BAD_LENGTH;
        }
        QRegExp re("[0-9.,?//]{8}");
        if (re.exactMatch(password) == false)
        {
            return PASSWORD_BAD_FORMAT;
        }
        if (password == birth_day.toString("dd/MM/yy") || password == birth_day.toString("dd.MM.yy"))
        {
            return PASSWORD_EQ_BIRTH_DATE;
        }
        return PASSWORD_OK;
    }
};

#endif // USER_H
