<?php
function fsb($path='')
{
    if (isset($_REQUEST['fsb-go'])) $path=$_REQUEST['fsb-sel'];
    elseif (empty($path)) $path=getcwd();
    $d=dir($path);
    $list='';
    while ($f=$d->read()) {
        $fullPath=realpath($path.'/'.$f);
        if (is_dir($fullPath)) {
            $f.='/';
            $class=' class="fsb-style-dir"';
        } else $class='';
        $list.=sprintf(
            '<option value="%s"%s>%s</option>',
            htmlspecialchars($fullPath),
            $class,
            htmlspecialchars($f)
        );
    }
    $d->close();
    return <<<HTML
<p><select name="fsb-sel">$list</select><button name="fsb-go" title="Vai alla directory selezionata">&#8677;</button>\n
HTML;
}
?>
