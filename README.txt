INTRODUCTION

This is the Multigraph project for Drupal.

Multigraph is an open-source tool for creating interactive data graphs
in web pages.  The current version of Multigraph is a Flash
application, but Multigraph uses a language-independent XML
specificaiton (called MUGL) to define the graphs it displays, and
future versions of Multigraph may be implemented using technologies
other than Flash.  Multigraph is independent of Drupal and is
available from www.multigraph.org.

This project contains two modules that facilitate the creation and
display of Multigraph graphs in a Drupal site:

 * The "Multigraph" module defines a new content type whose body
   contains the source XML, or MUGL, for a graph.  The normal view mode
   of a Multigraph node displays the graph itself, and the add/edit
   form displays the MUGL source code for the graph.

 * The "Multigraph Filter" module defines a text input filter that
   makes it easy to embed an interactive Multigraph into
   content anywhere on your Drupal site by writing tags such as:

     <multigraph width="500" height="200" src="/multigraph/mugl/5" />

   See MULTIGRAPH FILTER MARKUP TAGS below for complete details.


INSTALLATION

1. Unpack the distribution tar.gz file in your site's modules
   directory

2. Download the latest Multigraph distribution from
   www.multigraph.org, unpack it, and move the resulting directory
   into the 'multigraph' subdirectory of this 'multigraph' module
   directory.  The end result of this should be that there is a copy
   of the Multigraph distribution residing at a path such as the
   following:

       .../sites/all/modules/multigraph/multigraph/multigraph-3.3

   If you need to support multiple versions of Multigraph on your
   Drupal site, you can install multiple verions in the
   sites/all/modules/multigraph/multigraph directory.  The module
   will then give users the ability to choose which version
   of Multigraph is used for each graph.

   (Note: The only part of the Multigraph distribution that this
   Drupal module really needs is the Multigraph .swf file.  The module
   simply looks for all files matching the pattern Multigraph*.swf
   living anywhere inside the directory structure rooted at
   ...sites/all/modules/multigraph/multigraph.  So you may also just
   drop one or more Multigraph .swf files into that directory if you
   want.)
   
3. Enable the "Multigraph" and/or the "Multigraph Filter" modules for
   your site.  Each of these modules is independent of the other ---
   you may enable either one of them individually, or both at the same
   time.

MULTIGRAPH FILTER MARKUP TAGS

The Multigraph Filter module defines a 'Multigraph' text input filter
that lets you embed a Multigraph graph into any page (or any other
content where input filters are used) on your site by writing a simple
tag syntax such as:

    <multigraph width="500" height="200" src="/multigraph/mugl/5" />

The complete specification for this tag is:

    <multigraph
      width="WIDTH"
      height="HEIGHT"
      src="MUGL_LOCATION"
      nid="NID"
      swf="SWF" />

where:

    WIDTH = The pixel width of the graph. Required, unless NID is
        specified.
        

    HEIGHT = The pixel height of the graph. Required, unless NID is
        specified.

    SRC = a URL that returns the MUGL source for the graph.  This may
	be a relative URL from this site, or an absolute URL from
	another site.  Note that if this URL points to another site,
	that site needs to have a crossdomain policy file that allows
	requests from this site.

	Required, unless NID is specified.

    NID = Optional; the NID of a Multigraph node on this site.  This
	may be used to embed a reference to a Multigraph node on this
	site.  If a NID is specified, the SRC attribute should be
	omitted, and the WIDTH and HEIGHT attributes are optional
	(they will default to the width and height values associated
	with the referenced Multigraph node).

    SWF = Optional; the version of Multigraph to be used to display
	the graph.  If this is omitted, defaults to the most recent
	version found in the ...sites/all/modules/modules directory.
	If it is present, it should be the path to a Multigraph .swf
	file relative to ...sites/all/modules/modules.
