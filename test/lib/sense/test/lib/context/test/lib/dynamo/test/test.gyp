{
	'includes':[
		'lib/dynamo/def.gypi',
		'plank/def/mac-targets.gypi',
		'plank/def/cpp11.gypi'
	],#includes
	'target_defaults': {
		'target_name': 'test', 
		'type': 'executable',
		'sources': [
			'src/main.cpp',
			'src/batch.h'
		], #sources
		'include_dirs': [
			'plank/src/',
			'.'
		], #include_dirs		
	}, #target_defaults
}