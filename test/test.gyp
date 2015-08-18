{
	'includes':[
		'lib/numbro/def.gypi',
		'plank/def/plank.gypi',
	],#includes
	'target_defaults': {
		'target_name': 'test', 
		'type': 'executable',
		'sources': [
			'src/main.cpp',
			'src/test.h'
		], #sources
		'include_dirs': [
			'plank/src/',
			'.'
		], #include_dirs		
	}, #target_defaults
}