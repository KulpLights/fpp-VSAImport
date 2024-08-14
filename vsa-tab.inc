
<?
LoadPluginSettings("fpp-VSAImport");
?>

<script>
var tablesorterOptions_Override_vsa = {
        theme: 'fpp',
        headers: {
            0: { sorter: "text", sortInitialOrder: 'asc' },
            1: { sorter: "metric" },
            2: { sorter: "text" }
        },
        widgetOptions: {
            cssStickyHeaders_attachTo: '#divvsaData'
        }
};
var tablesorterOptions_vsa= $.extend(true,{}, tablesorterOptions_Common, tablesorterOptions_Override_vsa, {widgetOptions:{filter_hideFilters: (settings.fileManagerTableFilter =="1" ? false : true)}});

</script>
<style>
#VSAFrameRateRow .printSettingLabelCol {
    text-wrap: nowrap;
}
#VSAFrameRateRow {
    float: right;
}
#VSAUsePWMConfigRow .printSettingLabelCol {
    text-wrap: nowrap;
}
#VSAUsePWMConfigRow {
    float: right;
}

.vsaFormActions {
    margin-bottom: 0px;
}

</style>
<div class="tab-pane fade" id="tab-vsa" role="tabpanel" aria-labelledby="tab-vsa-tab">
    <div id="divvsa">
        <div class="backdrop">
            <legend> VSA Files </legend>
            <div id="divvsaData" class="fileManagerDivData">
                <table id="tblvsa" class="tablesorter">
                    <thead>
                    <tr>
                        <th>File</th>
                        <th class="sorter-metric" data-metric-name-full="byte|Byte|BYTE" data-metric-name-abbr="b|B">Size</th>
                        <th>Date Modified</th>
                    </tr>
                    </thead>
                    <tbody>
                    </tbody>
                </table>
            </div>
            <div class="row">
                <div class="col-auto">
                    <div class='vsaFormActions form-actions'>
                        <input onclick="ClearSelections('vsa');" class="buttons" type="button" value="Clear" />
                        <input onclick="ButtonHandler('vsa', 'fileInfo');" class="disableButtons singlevsaButton" type="button" value="VSA Info" />
                        <input onclick="ButtonHandler('vsa', 'generate');" class="disableButtons singlevsaButton" type="button" value="Generate FSEQ" />
                        <input onclick="ButtonHandler('vsa', 'download');" class="disableButtons singlevsaButton multivsaButton" type="button" value="Download" />
                        <input onclick="ButtonHandler('vsa', 'rename');" class="disableButtons singlevsaButton" type="button" value="Rename" />
                        <input onclick="ButtonHandler('vsa', 'delete');" class="disableButtons singlevsaButton multivsaButton" type="button" value="Delete" />
                    </div>
                </div>
                <div class="col" style="margin-top: 1em;">
                    <? PrintSetting('VSAFrameRate', '', array(), 'fpp-VSAImport') ?>
                </div>
            </div>
            <div class="row">
                <div class="col-auto">
                    <div class="note"><strong>CTRL+Click to select multiple items</strong></div>
                </div>
                <div class="col"">
                    <? PrintSetting('VSAUsePWMConfig', '', array(), 'fpp-VSAImport') ?>
                </div>
            </div>
        </div>
    </div>
</div>

<script>
 $('#tblvsa').on('mousedown', 'tbody tr', function(event,ui) {
    HandleMouseClick(event, $(this), 'vsa');
});

function FileInfovsa(filename) {
    $('#fileText').html("Getting VSA Info.");

    $.get("api/file/info/fpp-VSAImport/vsa/" + encodeURIComponent(filename), function (data) {
        DoModalDialog({
            id: "VSAViewer",
            title: "VSA Information",
            class: "modal-lg modal-dialog-scrollable",
            body: '<pre>' + syntaxHighlight(JSON.stringify(data, null, 2)) + '</pre>',
            keyboard: true,
            backdrop: true,
            buttons: {
                "Close": function() {
                    CloseModalDialog("VSAViewer");
                    ClearSelections("vsa");
                }
            }
        });
    });
}
function vsageneratePressed(filename) {
    $.get("api/file/onUpload/vsa/" + encodeURIComponent(filename), function (data) {
        GetAllFiles();
        DoModalDialog({
            id: "VSA",
            title: "VSA",
            class: "modal-lg modal-dialog-scrollable",
            body: '<pre>' + data + '</pre>',
            keyboard: true,
            backdrop: true,
            buttons: {
                "Close": function() {
                    CloseModalDialog("VSA"); 
                    ClearSelections("vsa");                   
                }
            }
        });
    });

}
</script>
