<?php

function _multigraph_available_swf_path_allowed_values() {
  $allowed_values = array();
  foreach (_multigraph_available_swf_paths() as $swf_path) {
    $allowed_values[$swf_path] = $swf_path;
  }
  return $allowed_values;
}

function _multigraph_available_swf_paths() {
  $swf_dir = drupal_get_path('module', 'multigraph') . '/swfs';
  $handle = opendir($swf_dir);
  $swf_paths = array();
  while (false !== ($entry = readdir($handle))) {
    if (preg_match('|^multigraph.*\.swf$|i', $entry)) {
      $swf_paths[] = $entry;
    }
  }
  closedir($handle);
  arsort($swf_paths);
  return $swf_paths;
}

function _multigraph_object_embed_string($width,$height,$mugl_url,$swf) {
    return (''
    	   . '<object'
	   .    ' id="mgid"'
           .    ' classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"'
           .    ' width="'.$width.'"'
           .    ' height="'.$height.'"'
           .    ' codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,40,0">'
           .   '<param name="quality" value="best" />'
           .   '<param name="scale" value="exactfit" />'
           .   '<param name="wmode" value="opaque" />'
           .   '<param name="bgcolor" value="#ffffff" />'
           .   '<param name="src" value="'.$swf.'" />'
           .   '<param name="name" value="mgid" />'
           .   '<param name="allowfullscreen" value="false" />'
           .   '<param name="allowScriptAccess" value="sameDomain" />'
           .   "<param name='flashvars' value='muglfile=".$mugl_url."'>"
           .   '<param name="align" value="middle" />'
           .   '<embed'
           .      ' id="mgid"'
           .      ' type="application/x-shockwave-flash"'
           .      ' width="'.$width.'"'
           .      ' height="'.$height.'"'
           .      ' src="'.$swf.'"'
           .      ' name="mgid"'
           .      ' bgcolor="#ffffff"'
           .      ' wmode="opaque"'
           .      ' scale="exactfit"'
           .      ' quality="best"'
           .      ' allowfullscreen="false"'
           .      ' allowscriptaccess="sameDomain"'
           .      " flashvars='muglfile=".$mugl_url."'"
           .      ' align="middle">'
           .   '</embed>'
           . '</object>'
  );
}
