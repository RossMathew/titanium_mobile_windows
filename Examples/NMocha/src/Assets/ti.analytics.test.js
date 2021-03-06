/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var should = require('./should'),
	utilities = require('./utilities/utilities');

describe('Titanium.Analytics', function () {

	it('lastEvent', function () {
		should(Ti.Analytics.lastEvent).not.be.undefined;
		should(Ti.Analytics.lastEvent).be.a.Object;
		should(Ti.Analytics.getLastEvent).not.be.undefined;
		should(Ti.Analytics.getLastEvent).be.a.Function;
	});

	it('featureEvent', function () {
	    should(Ti.Analytics.featureEvent).not.be.undefined;
	    should(Ti.Analytics.featureEvent).be.a.Function;
	});

    // TODO: implement Titanium.Analytics.filterEvents
	it.skip('filterEvents', function () {
	    should(Ti.Analytics.filterEvents).not.be.undefined;
	    should(Ti.Analytics.filterEvents).be.a.Function;
	});

	it('navEvent', function () {
	    should(Ti.Analytics.navEvent).not.be.undefined;
	    should(Ti.Analytics.navEvent).be.a.Function;
	});

	it('featureEvent validate limitations', function () {
	    var payloads = require('./featureEventPayload.json'),
	        tests = {
	            "largeInvalid": -1,
	            "complexInvalid": -1,
	            "complexValid": 0,
	            "maxKeysInvalid": -1
	        };
	    for (t in tests) {
	        should(Ti.Analytics.featureEvent(tests[t], payloads[t])).be.eql(tests[t]);
	    }
	});
});
