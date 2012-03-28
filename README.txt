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
   makes it possible to embed an interactive Multigraph into
   content on your Drupal site by writing tags such as:

      <multigraph width="500" height="200" src="/multigraph/mugl/5"/>

   See MULTIGRAPH FILTER MARKUP TAGS below for complete details.


INSTALLATION

1. unpack the distribution tar.gz file in your site's modules
   directory
2. download the latest Multigraph distribution from www.multigraph.org,
   unpack it, and put the Multigraph.swf file from that distribution into
   the 'swfs' subdirectory.  You can put multiple swf files here if
you want to have access to more than one version of Multigraph
on your site --- just make sure ...
   
3. Enable the "Multigraph" and/or the "Multigraph Filter" modules for your site.
   Each of these modules is independent of ther other --- you may enable either
   one of them individually, or both at the same time.


MULTIGRAPH FILTER MARKUP TAGS

<multigraph width="WIDTH" height="HEIGHT" src="MUGL_LOCATION" nid="
