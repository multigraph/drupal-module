<?php
// $Id$

/**
 * @file
 * Default theme implementation for rendering multigraph graph
 *
 * Available variables:
 * - $graph:  the graph
 */
?>
<div id="multigraph graph">
   This is a placeholder for a graph of size <?php print $width; ?> X <?php print $height; ?>, with the 
   following MUGL:
   <textarea cols="60" rows="10" readonly="readonly"><?php print $mugl; ?></textarea>
</div>
