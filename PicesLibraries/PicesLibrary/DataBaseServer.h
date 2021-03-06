#if  !defined(_DATABASESERVER_)
#define  _DATABASESERVER_


/**
 *@class MLL::DataBaseServer
 *@brief  Represents the parameters for a single Database Server.  
 *@details  Things like UserName, HostName, etc.   The "DataBase"  class will use one instance
 *          of this object to use as connection parameters.
 */


#include "KKQueue.h"
#include "RunLog.h"
#include "KKStr.h"
using namespace KKB;

namespace MLL 
{
  class  DataBaseServer
  {
  public:
    typedef  DataBaseServer*        DataBaseServerPtr;
    typedef  DataBaseServer const * DataBaseServerConstPtr;

    DataBaseServer ();
    DataBaseServer (const DataBaseServer&  dataBaseServer);
    DataBaseServer (const KKStr&           parameterStr);

    ~DataBaseServer ();

    const KKStr&  DataBaseName ()  const  {return dataBaseName;}
    const KKStr&  Description  ()  const  {return description;}
    bool          Embedded     ()  const  {return embedded;}
    const KKStr&  HostName     ()  const  {return hostName;}
    const KKStr&  MySqlDataDir ()  const  {return mySqlDataDir;}
    const KKStr&  PassWord     ()  const  {return passWord;}
    kkuint32      PortNum      ()  const  {return portNum;}
    const KKStr&  UserName     ()  const  {return userName;}

    void  DataBaseName (const KKStr&  _dataBaseName)  { dataBaseName = _dataBaseName;}
    void  Description  (const KKStr&  _description)   { description  = _description;}
    void  Embedded     (bool          _embedded)      { embedded     = _embedded;}
    void  HostName     (const KKStr&  _hostName)      { hostName     = _hostName;}
    void  MySqlDataDir (const KKStr&  _mySqlDataDir)  { mySqlDataDir = _mySqlDataDir;}
    void  PassWord     (const KKStr&  _passWord)      { passWord     = _passWord;}
    void  PortNum      (kkuint32      _portNum)       { portNum      = _portNum;}
    void  UserName     (const KKStr&  _userName)      { userName     = _userName;}


    KKStr  ServerDescription ()  const;  // Get description of server for info display

    KKStr  ToParameterStr ()  const;

  private:
    void  ParseParameterStr (const  KKStr&  parameterStr);

    KKStr     dataBaseName;
    KKStr     description;
    bool      embedded;
    KKStr     hostName;
    KKStr     mySqlDataDir;   /**< Used with Embedded server. */
    KKStr     userName;
    KKStr     passWord;
    kkuint32  portNum;
  };  /* DataBaseServer */


  typedef  DataBaseServer::DataBaseServerPtr  DataBaseServerPtr;

  typedef  DataBaseServer::DataBaseServerConstPtr  DataBaseServerConstPtr;

#define  _DataBaseServer_Defined_

  class  DataBaseServerList: public  KKQueue<DataBaseServer>
  {
  public:
    typedef  DataBaseServerList*  DataBaseServerListPtr;

    DataBaseServerList (RunLog&  _log,                         // Will load lost from "MySql.cfg" file in "%PicesHomeDir%\Configurations" directory
                        bool     _loadFromConfigFile = true    // if set to false will create an empty list.
                       );

    DataBaseServerList (const DataBaseServerList&  serverList);

   ~DataBaseServerList ();


    const KKStr&        DefaultServerDescription ()  const  {return defaultServerDescription;}
    void                DefaultServerDescription (const KKStr&   _defaultServerDescription)  {defaultServerDescription = _defaultServerDescription;}

    DataBaseServerPtr   LookUpByDescription (const KKStr&  _description);

    DataBaseServerPtr   GetDefaultServer ();   /**< Will return a pointer to the DataBaseServer instance that
                                                * has the same description as "defaultServerDescription".
                                                */
  
    RunLog&   Log ()   {return  log;}

    void  WriteConfigFile ()  const;

  private:
    void  ReadConfigFile ();

    KKStr  defaultServerDescription;

    RunLog&  log;
  };


  typedef  DataBaseServerList::DataBaseServerListPtr  DataBaseServerListPtr;

}  /* namespace MLL */

#endif
