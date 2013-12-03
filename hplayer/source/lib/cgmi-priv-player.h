#ifndef __GST_PLAYER_H__
#define __GST_PLAYER_H__


#ifdef __cplusplus
extern "C"
{
#endif
typedef struct
{
   void*          cookie;
   GMainContext   *thread_ctx; 
   GThread        *thread;
   gchar          *playbackURI; /* URI to playback */
   gchar          *manualPipeline; /* URI to playback */
   GMainLoop      *loop;
   GstElement     *pipeline;
   GstElement     *source;
   guint          tag;
   GstElement     *videoSink;
   GstElement     *demux;
   GstElement     *appsink;
   GstBus         *bus;
   GstMessage     *msg;
   void*          usrParam;

   /* user registered data */ 
   cgmi_EventCallback eventCB;
}tSession;

gboolean cisco_gst_init( int argc, char *argv[] );
void cisco_gst_deinit( void );
gint cisco_gst_set_pipeline(tSession *pSession, char *uri, const char *manualPipeline );
tSession*  cisco_create_session(void * usrParam);
void cisco_delete_session(tSession *pSession);

gint cisco_gst_play(tSession *pSession  );
gint cisco_gst_pause(tSession *pSession  );

 void debug_cisco_gst_streamDurPos( tSession *pSession );
#ifdef __cplusplus
}
#endif

#endif 

