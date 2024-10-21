/*############################################    MODE     ############################################*/
/*
 * Modes de fonctionnement :
 *
 * MODE_GSM : Utilisé pour le mode GSM. Ce mode envoie les données via le réseau GSM.
 * MODE_SAT : Utilisé pour le mode SAT (Satellite). Ce mode envoie les données via des réseaux satellitaires.
 *
 *
 * Tableau g_config_network_modes[2] :
 *   - Le premier élément représente le réseau de démarrage (par défaut).
 *   - Le deuxième élément représente le réseau de secours (utilisé en cas d'échec du premier).
 *
 *   Full gsm : g_config_network_modes[2] = {MODE_GSM, MODE_GSM};
 *   Full sat : g_config_network_modes[2] = {MODE_SAT, MODE_SAT};
 *   Hybride start gsm : g_config_network_modes[2] = {MODE_GSM, MODE_SAT};
 *   Hybride start sat : g_config_network_modes[2] = {MODE_SAT, MODE_GSM};
 */

//#define MODE_MIXTE 3  // Ajout d'un mode mixte pour basculer entre réseaux

uint8_t DEFAULT_MODE = MODE_GSM;  // Par défaut, on démarre en mode GSM (pour le chargment des configuration a distance, l'envoie de logs...)
uint8_t g_config_network_modes[2] = {MODE_GSM, MODE_SAT};  // Tableau des réseaux : GSM puis SAT


/*#####################################    ACQUISITION GNSS     ########################################*/
/*
 * Configurations pour l'acquisition des données GNSS (GPS) :
 *
 * g_config_GNSS_interval_time : Temps entre deux prises de positions GNSS, en millisecondes.
 *                              La valeur minimale est de 1000 ms (soit 1 seconde).
 */

ULONG g_config_GNSS_interval_time = 1000;  // Délai entre deux prises de position (ms), MIN = 1000 ms


/*############################################    GSM     ############################################*/
/*
 * Configurations pour le mode GSM :
 *
 * g_config_SEND_interval_time_GSM : Temps entre deux envois de message en mode GSM, en millisecondes.
 *                                   La valeur minimale est de 1000 ms (1 seconde).
 *
 * g_config_max_nb_point_per_message_GSM : Nombre maximum de points à envoyer dans un seul message en mode GSM.
 *                                         La valeur minimale est de 10 points et la valeur maximale est de 65 points.
 *
 * S'il n'y a qu'un point a envoyer on en envoie qu'un, si on en X * g_config_max_nb_point_per_message_GSM point, on envois X message de g_config_max_nb_point_per_message_GSM points
 *
 * g_config_POP_mode_GSM : Mode de gestion des messages pour le GSM. Peut être configuré à POP_MODE_LIFO, POP_MODE_FIFO, etc., la description des modes est expliqué plus bas
 */

ULONG g_config_SEND_interval_time_GSM = 1000;  // Délai entre deux envois de message GSM (ms), MIN = 1000 ms
ULONG g_config_max_nb_point_per_message_GSM = 60;  // Nombre maximum de points par envoi en mode GSM, MIN = 10, MAX = 65
uint8_t g_config_POP_mode_GSM = POP_MODE_LIFO;  // Mode de gestion de la pile pour GSM (LIFO)

ULONG g_config_no_connexion_change_time_from_GSM = 3*60*1000;//durée de perte de connexion avant changement de reseau (ms)


/*############################################    NTN (SATELLITE)     ############################################*/
/*
 * Configurations pour le mode SAT (Satellite) :
 *
 * g_config_SEND_interval_time_SAT : Temps entre deux envois de message en mode SAT, en millisecondes.
 *                                   La valeur minimale est de 60000 ms (soit 1 minute).
 *
 * g_config_max_nb_point_per_message_SAT : Nombre maximum de points à envoyer dans un seul message en mode SAT.
 *                                         La valeur minimale est de 10 points et la valeur maximale est de 65 points.
 *
 * g_config_POP_mode_SAT : Mode de gestion des messages pour le SAT. Peut être configuré à POP_MODE_LIFO, POP_MODE_FIFO, etc.
 */

ULONG g_config_SEND_interval_time_SAT = 60000;  // Délai entre deux envois de message SAT (ms), MIN = 60000 ms
ULONG g_config_max_nb_point_per_message_SAT = 60;  // Nombre maximum de points par envoi en mode SAT, MIN = 10, MAX = 65
uint8_t g_config_POP_mode_SAT = POP_MODE_LIFO_LIVE;  // Mode de gestion de la pile pour SAT (LIFO_LIVE)

ULONG g_config_no_connexion_change_time_from_SAT=2*60*1000;//durée de perte de conexion avant changement de reseau (ms)

ULONG g_config_connected_force_change_time_from_SAT=5*60*1000;//duré avant retour vers le mode par defaut meme si on est connecté : X min ou 0 pour desactive la fonction

/*############################################    POP MODES     ############################################*/
/*
 * Modes de gestion de la pile (Stack) pour l'envoi des messages :
 *
 * POP_MODE_LIFO : Last In, First Out. Les messages les plus récents sont envoyés en premier.
 * POP_MODE_FIFO : First In, First Out. Les messages les plus anciens sont envoyés en premier.
 * POP_MODE_LIFO_LIVE : LIFO avec gestion live. Ce mode permet d'envoyer les messages live les plus récents
 * POP_MODE_FIFO_LIVE : FIFO avec gestion live. Ce mode permet d'envoyer les messages live les plus anciens
 *
 * Vous pouvez configurer le mode de gestion des messages séparément pour le GSM et le SAT.
 */

