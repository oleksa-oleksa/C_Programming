/*Blockiere andere Signale, während ein Signal Handler gerade aktiv ist. Das ist ziemlich einfach zu erreichen, indem man einfach entsprechende SIG_IGN in den Signal Handler einbaut, wie es im folgenden Beispiel gemacht wurde: */

void sighdlr() {
  /* andere Signale blockieren */
  signal(SIGINT, SIG_IGN);
  signal(SIGABRT, SIG_IGN);
  signal(SIGHUP, SIG_IGN);

  /* hier kommt der eigentliche Signal Handler rein */

  exit(0);
}


/*Ignoriere Signale solange nicht-atomare Prozess-Modifikationen aktiv sind. Die Vorgehensweise ist hierbei ähnlich wie beim Blocken von Signalen während ein Signal Handler aktiv ist. Ein Beispiel dazu könnte wie folgt aussehen:
*/

signal(SIGINT, SIG_IGN);
signal(SIGABRT, SIG_IGN);
signal(SIGHUP, SIG_IGN);

setuid(0);
/* der kritische Code kommt hier hin */

setuid(getuid()); // und hier endet der kritische Code

/* setze die Signale wieder zurueck auf ihre Default-Aktion */
signal(SIGINT, SIG_DFL);
signal(SIGABRT, SIG_DFL);
signal(SIGHUP, SIG_DFL);

/* ...weiterer Code... */
