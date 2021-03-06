#ifndef _LIBCOMMON_H_
#define _LIBCOMMON_H_

#ifndef __GNUC__
#define __attribute__(x) /*NOTHING*/
#endif

#ifndef LOCALEDIR
#define LOCALEDIR "/usr/share/locale"
#endif

#ifdef HAVE_LOCALE_H
#include <locale.h>
#endif

#ifdef ENABLE_NLS
  #include <libintl.h>

  #define _(Text) gettext(Text)

  #ifdef gettext_noop
    #define N_(String) gettext_noop(String)
  #else
    #define N_(String) (String)
  #endif

  #define P_(singular, plural, number) ngettext(singular, plural, number)
#else
  #undef bindtextdomain
  #define bindtextdomain(Domain, Directory) /* empty */
  #undef textdomain
  #define textdomain(Domain) /* empty */
  #define _(Text) (Text)
  #define N_(Text) (Text)
  #define P_(singular, plural, number) (number == 1 ? singular : plural)
#endif

// getfd.c
int getfd(const char *fnam);

// version.c
const char *get_progname(void);
void set_progname(const char *name);
void print_version_and_exit(void);

// error.c
void kbd_warning(const int errnum, const char *fmt, ...);
void kbd_error(const int exitnum, const int errnum, const char *fmt, ...);

// xmalloc.c
#include <sys/param.h>

void nomem(void);
void *xmalloc(size_t sz);
void *xrealloc(void *p, size_t sz);
char *xstrdup(char *p);
char *xstrndup(char *p, size_t n);
void *xfree(void *p);

#endif /* _LIBCOMMON_H_ */
