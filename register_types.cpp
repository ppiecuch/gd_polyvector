#include "register_types.h"
#include "polyvector.h"
#include "resource_importer_swf.h"


static Ref<ResourceLoaderJSONVector> resource_loader_jsonvector;

void register_gd_polyvector_types()
{
	ClassDB::register_class<PolyVector>();
	ClassDB::register_class<JSONVector>();
	
	resource_loader_jsonvector.instance();
	ResourceLoader::add_resource_format_loader(resource_loader_jsonvector);
	
#ifdef TOOLS_ENABLED
	Ref<ResourceImporterSWF> swfdata;
	swfdata.instance();
	ResourceFormatImporter::get_singleton()->add_importer(swfdata);
#endif
}

void unregister_gd_polyvector_types()
{
	ResourceLoader::remove_resource_format_loader(resource_loader_jsonvector);
	resource_loader_jsonvector.unref();
}

