#ifndef CONTAINERWIGET_H
#define CONTAINERWIGET_H

#include "wtinclude.h"
#include <random>
#include "eCore/db.h"
#include "inlinestyle.h"
#include "bootstrap.h"

#include <QString>

class ContainerWidget : public WContainerWidget
{
public:


    ContainerWidget(const std::string &title = "" );

    WContainerWidget* Header();
    WContainerWidget* Content();
    WContainerWidget* Footer();

    void setTitleBarBackColor( const std::string& color = Style::color::Purple::MidnightBlue );

    void setBackGroundImg( const std::string& url ,
                           const std::string& size = Style::background::size::cover ,
                           const std::string& repeat = Style::background::repeat::norepeat ,
                           const std::string& position = Style::background::position::center_center );



    WPushButton *askConfirm( const std::string& question );


    /**
     * @brief createDialog:  WDialog Oluşturur ve Geri ptr Geri Döndürür.
     * @return
     */
    WDialog* createDialog( const std::string& title = "" );

    void remogeDialog( WDialog* mDialog );

    enum ContainerStyleType
    {
        ROW = 0,
        CONTAINERFLUID
    };


    void setContainerStyle(ContainerStyleType type);

    inline int getRandom(int begin = 0 , int end = 127 ) const
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(begin,end);
        return dist(mt);
    }

    inline std::string rgbaRandom(){

        return WString("{1},{2},{3}").arg (this->getRandom (150,200))
                .arg (this->getRandom (170,220))
                .arg (this->getRandom (180,230)).toUTF8 ();
    }

    void showMessage( std::string title , std::string msg , std::string btnText = "Tamam");


    /**
     * @brief showPopUpMessage : Mesaj Gönder
     * @param msg
     * @param infoType info,msg ve boşluk
     */
    void showPopUpMessage(const std::string & msg , const std::string &infoType = "info" );///*msg*/


    ///
    /// \brief removeTitleBar: Eğer Title Mevcutsa Container da Bulunan Başlığı Siler.
    ///
    void removeTitleBar();


private:
    WContainerWidget* mHeaderContainer;
    WContainerWidget* mContentContainer;
    WContainerWidget* mFootContainer;

    WContainerWidget* mTitleBar;
    std::string mTitle;



};



class FileUploaderWidget : public ContainerWidget
{
public:
    explicit FileUploaderWidget( const std::string &title = "PDF Cevap Yükle" );





    /**
     * @brief isUploaded: Check file is Uploaded
     * @return
     */
    bool isUploaded() const;





    /**
     * @brief The FilterType enum: Selectable File Type
     */
    enum FilterType{
        Pdf,
        Image
    };





    /**
     * @brief setType: File Type
     * @param type: Pdf , Image
     */
    void setType( FilterType type );






    /**
     * @brief fileLocation: Location is FULL PATH
     * @return
     */
    QString fileLocation() const;





    /**
     * @brief doocRootLocation: Location is Without docroot folder
     * @return
     */
    QString doocRootLocation() const;




    /**
     * @brief Uploaded: Signal Triggered When File Uploaded
     * @return
     */
    Signal<NoClass> &Uploaded();

private:
    WFileUpload* mFileUploader;

    QString mFileLocation;
    QString mDoocRootLocation;

    bool mIsUploaded;

    Signal<NoClass> _Uploaded;

    FilterType mType;
};


#endif // CONTAINERWIGET_H
