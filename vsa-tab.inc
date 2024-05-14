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


<div class="tab-pane fade" id="tab-vsa" role="tabpanel" aria-labelledby="tab-vsa-tab">
    <div id="divLogs">
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

        <div class='form-actions'>
        <input onclick="ClearSelections('vsa');" class="buttons" type="button" value="Clear" />
        <input onclick="ButtonHandler('vsa', 'fileInfo');" class="disableButtons singlevsaButton" type="button" value="VSA Info" />
        <input onclick="ButtonHandler('vsa', 'download');" class="disableButtons singlevsaButton multiLogsButton" type="button" value="Download" />
        <input onclick="ButtonHandler('vsa', 'rename');" class="disableButtons singlevsaButton" type="button" value="Rename" />
        <input onclick="ButtonHandler('vsa', 'delete');" class="disableButtons singlevsaButton multiLogsButton" type="button" value="Delete" />
        </div>
        <div class="note"><strong>CTRL+Click to select multiple items</strong></div>
    </div>
    </div>
</div>


<script>
 $('#tblvsa').on('mousedown', 'tbody tr', function(event,ui) {
    HandleMouseClick(event, $(this), 'vsa');
});

function FileInfovsa(filename) {
    $('#fileText').html("Getting VSA Info.");

    $.get("api/file/info/fpp-VSAImport/vsa/" + filename, function (data) {
        DoModalDialog({
            id: "VSAViewer",
            title: "VSA Information",
            class: "modal-lg modal-dialog-scrollable",
            body: '<pre>' + syntaxHighlight(JSON.stringify(data, null, 2)) + '</pre>',
            keyboard: true,
            backdrop: true,
            buttons: {
                "Close": function() {CloseModalDialog("VSAViewer");}
            }
        });
    });
}
</script>